# Ksharim (reverse-engineering project)

Ksharim ("קשרים") was a commercial Hebrew document conversion utility from the late 1990s, designed to convert files between a wide range of word processor formats popular at the time.

---

This repository is primarily academic in nature — a preservation effort documenting the software's copy-protection mechanism through reverse engineering. If you happen to have documents that require Ksharim to convert, follow the steps below.

1. **Set up the emulator:** Install [SheepShaver](https://sheepshaver.cebix.net/) and install Apple Mac OS 9.0.4 inside it. Plenty of guides are available online. Installing Hebrew language packs is recommended.

2. **Install Ksharim:** Import `assets/Ksharim_9.sea` into the emulator and extract it using StuffIt Expander, then proceed with the installation.

3. **Get your Machine ID:** Launch Ksharim. An activation dialog will appear displaying your Machine ID (e.g. `QB10C-334-00220-765`).

4. **Generate your key:** Compile and run `assets/Ksharim_key-generator.cpp`, enter your Machine ID when prompted, and two candidate activation keys will be generated. Try both. Good luck.

---

## Supported Formats
Einstein, Qtext, Word 97-2003, PowerPoint, RTF, AppleWorks, Rav-Ktav, Rav-Daf, NisusWriter 4/5/6, WordWrite, Plain Text.

---


## **Legal Disclaimer / Abandonware Notice**
This repository, including the original software files ("Ksharim 9") and the associated Keygen, is published strictly for educational purposes, reverse engineering research, and digital preservation.
The original software was developed by its original creators and is currently considered "Abandonware"—it has not been supported, sold, or maintained for over two decades. All copyrights and intellectual property rights for the original software remain the sole property of their respective legal owners.
The purpose of this project is not to generate any financial profit or to infringe upon the developer's rights, but solely to allow the continued operation of this legacy software on modern hardware or emulation environments for users who rely on it, as there is no longer any legal avenue to purchase a valid activation key.
All materials are provided “as-is”, without warranty of any kind, and users are responsible for complying with applicable laws in their jurisdiction.

**To the Copyright Holders:** If you are the legal copyright holder of this software and object to its distribution in this archival format, please contact me directly, and the repository will be taken down immediately.
