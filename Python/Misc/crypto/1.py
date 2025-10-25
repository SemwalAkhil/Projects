import subprocess
import sys
import os


def run_keymath(hex_hash, operation):
    cmd = f"./keymath {hex_hash} {operation}"
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    out, err = p.communicate()
    if err:
        print(f"keymath error for {cmd}: {err.decode().strip()}")
    for line in out.decode().splitlines():
        if line.lower().startswith("result:"):
            return line.split("Result:")[-1].strip()
    print(f"No result parsed for {cmd}")
    return None

def run_keysub(hex_hash, operation):
    cmd = f"./keysubtracter -p {hex_hash} {operation}"
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    out, err = p.communicate()
    if err:
        print(f"keysubtracter error for {cmd}: {err.decode().strip()}")
    for line in out.decode().splitlines():
        if line.lower().startswith("result:"):
            return line.split("Result:")[-1].strip()
    print(f"No result parsed for {cmd}")
    return None

def check(file_name:str):
    # Initialize counters
    count = 0
    with open(file_name, "r") as infile:
        for line in infile:
            for char in line:
                if char.isupper() or char.isdigit():
                    count += 1
    return count

# === Configuration ===
output_file    = "output.txt"
repeat_process = 8
current_hash = "02145d2611c823a396ef6712ce0f712f09b9b4f3135e3e0aa3230fb9b6d08d1e16" # HASH HERE

# === MAIN ===
"""
output1.txt -> hash after r1
output2.txt -> hash after r2
output.txt -> final hash after comparing r1 and r2
"""
with open(output_file,"w") as outfile:
    for i in range(1, repeat_process + 1):
        key1 = run_keymath(current_hash, "/ 2")
        run_keysub(key1, "-x -f address -l compress -r A:B -n 10 -o output1.txt")
        key2 = run_keymath(current_hash, "- 1")
        key3 = run_keymath(key2, "/ 2")
        run_keysub(key3,"-x -f address -l compress -r A:B -n 10 -o output2.txt")
        s1 = check("output1.txt") or None
        s2 = check("output2.txt") or None
        if s1 is None or s2 is None:
            print(f"invalid hash or scoring for {current_hash}")
            sys.exit(1)
        current_hash = key3 if s1 > s2 else key1
        os.remove("output1.txt")
        os.remove("output2.txt")
    outfile.write(current_hash + "\n" if current_hash else "\n")

print(f"Processing complete. Results written to: {output_file}")