#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cstdint>

// Checksum algorithm
uint32_t CalculateChecksum(const unsigned char* buffer, int size) {
    uint32_t sum = 0;
    uint16_t r = 55665;
    const uint16_t C1 = 52845;
    const uint16_t C2 = 22719;
    for (int i = 0; i < size; ++i) {
        uint8_t cipher = buffer[i] ^ (r >> 8);
        r = (static_cast<uint16_t>(cipher) + r) * C1 + C2;
        sum += cipher;
    }
    return sum;
}

// C++ implementation of the number-to-padded-string function
std::string FormatIntegerPadded(uint32_t number, int width) {
    std::stringstream ss;
    ss << std::setw(width) << std::setfill('0') << number;
    return ss.str();
}

/**
 * Key generation algorithm.
 * Takes the machine's unique seed string and a key type ('7' or '3')
 * and returns a valid activation key.
 */
std::string generate_key(const unsigned char* key_seed, int seed_size, char key_type) {
    char key_type_byte = key_type;

    // Step 1: Calculate the 3-digit internal number for Part 1
    uint32_t part1_internal_num = static_cast<uint8_t>(key_seed[1]) +
                                   static_cast<uint8_t>(key_seed[0]) * 10;
    std::string part1_3_digit_str = FormatIntegerPadded(part1_internal_num, 3);

    // Assemble the final 4-digit string for Part 1 by appending the key type byte
    std::string part1_str_final = part1_3_digit_str + key_type_byte;

    // Step 2: Calculate Part 2 by checksumming the entire seed
    uint32_t part2_num = CalculateChecksum(key_seed, seed_size);
    std::string part2_str_final = FormatIntegerPadded(part2_num, 4);

    // Step 3: Assemble the composite 9-byte buffer for the Part 3 checksum
    unsigned char part3_input_buffer[9];
    memcpy(&part3_input_buffer[0], part1_str_final.c_str(), 4);
    part3_input_buffer[4] = '-';
    memcpy(&part3_input_buffer[5], part2_str_final.c_str(), 4);

    // Step 4: Calculate the final number for Part 3
    uint32_t part3_num = CalculateChecksum(part3_input_buffer, 9);
    std::string part3_str_final = FormatIntegerPadded(part3_num, 4);

    // Step 5: Assemble and return the final key
    return part1_str_final + "-" + part2_str_final + "-" + part3_str_final;
}

int main() {
    std::string machine_id;
    std::cout << "--- Kesharim Keygen ---" << std::endl;
    std::cout << "Enter the Machine ID string (e.g., QB110-667-00000-978): ";
    std::getline(std::cin, machine_id);

    if (machine_id.length() < 4) { // Basic sanity check
        std::cerr << "Error: Machine ID is too short." << std::endl;
        return 1;
    }

    const unsigned char* seed_bytes =
        reinterpret_cast<const unsigned char*>(machine_id.c_str());
    int seed_size = machine_id.length();

    // Generate both possible keys based on the two valid key type bytes ('7' and '3')
    std::string key_type_7 = generate_key(seed_bytes, seed_size, '7');
    std::string key_type_3 = generate_key(seed_bytes, seed_size, '3');

    std::cout << "\nGenerated Keys for Machine ID: " << machine_id << std::endl;
    std::cout << "Key (Type 7): " << key_type_7 << std::endl;
    std::cout << "Key (Type 3): " << key_type_3 << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "\nTry both keys in the activation dialog." << std::endl;

    return 0;
}
