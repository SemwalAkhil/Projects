# !/usr/bin/python3

import binascii
import os
import hashlib
from bitcoin import privtopub, encode_pubkey, pubkey_to_address
import re

def is_valid_hex(s, length):
    """Check if the string s is a valid hexadecimal with the specified length."""
    try:
        return len(s) == length and all(c in '0123456789abcdefABCDEF' for c in s)
    except TypeError:
        return False

def convert_privkey_to_addresses(privkey_hex):
    """Convert a hexadecimal private key to both compressed and uncompressed Bitcoin addresses."""
    privkey_hex = privkey_hex.strip().zfill(64)  # Ensure it's 64 chars, padding with zero if necessary
    if not is_valid_hex(privkey_hex, 64):
        raise ValueError("Invalid hexadecimal private key. Ensure it is 64 characters long.")
    
    try:
        # Convert private key to uncompressed public key
        pubkey_uncompressed = encode_pubkey(privtopub(privkey_hex), "hex")
        # Convert private key to compressed public key
        pubkey_compressed = encode_pubkey(privtopub(privkey_hex), "hex_compressed")

        # Convert both public keys to Bitcoin addresses
        address_uncompressed = pubkey_to_address(pubkey_uncompressed)
        address_compressed = pubkey_to_address(pubkey_compressed)

        return address_compressed, address_uncompressed

    except Exception as e:
        raise ValueError(f"Error during conversion of private key to addresses: {e}")

def process_files(input_file, output_file):
    """Read private keys from input file, convert them to addresses, and write results to output file."""
    if not os.path.isfile(input_file):
        print(f"Error: Input file '{input_file}' does not exist.")
        return

    try:
        with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
            for line in infile:
                privkey_hex = line.strip()
                if privkey_hex:
                    try:
                        address_compressed, address_uncompressed = convert_privkey_to_addresses(privkey_hex)
                        
                        # Check if both addresses start with '12'
                        # if address_compressed.startswith('12') and address_uncompressed.startswith('12'):
                        if re.search(r"^[0-9][0-9]",address_compressed) or re.search(r"^[0-9][0-9]",address_uncompressed):
                            # Write the hexadecimal private key to the output file
                            outfile.write(f"Matching private key (Hex): {privkey_hex}\n")
                            outfile.write(f"Compressed Address: {address_compressed}\n")
                            outfile.write(f"Uncompressed Address: {address_uncompressed}\n\n")
                    except ValueError as e:
                        outfile.write(f"Error processing key {privkey_hex}: {e}\n")
                else:
                    outfile.write("Error: Empty line encountered in input.\n")
    except IOError as e:
        print(f"Error reading or writing files: {e}")

if __name__ == "__main__":
    input_file = 'input.txt'  # Replace with your input file name
    output_file = 'output.txt'  # Replace with your output file name
    process_files(input_file, output_file)
