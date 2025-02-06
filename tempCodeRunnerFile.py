import hashlib
import random

def encrypt_code(code: str) -> str:
    if not code.isdigit() or len(code) != 4:
        raise ValueError("Input must be a 4-digit numeric string.")
    
    # Generate a random salt of 4 digits
    salt = str(random.randint(1000, 9999))
    
    # Hash the input code combined with the salt
    hash_digest = hashlib.sha256((code + salt).encode()).hexdigest()
    numeric_hash = ''.join(str(int(c, 16)) for c in hash_digest[:8])
    
    # Mix the hash and salt to create a 12-digit encrypted code
    encrypted_code = numeric_hash[:6] + salt[:2] + numeric_hash[6:] + salt[2:]
    
    return encrypted_code[:12]  # Ensure it's exactly 12 digits

# Example usage:
encrypted = encrypt_code("1234")
print("Encrypted Code:", encrypted)
