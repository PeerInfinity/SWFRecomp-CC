#!/usr/bin/env python3
"""
Test script for EXTENDS opcode (0x69)

This creates a comprehensive SWF that tests the ActionScript 2.0 extends keyword
for setting up prototype-based inheritance between classes.

The EXTENDS opcode sets up the prototype chain between two constructor functions.

Test Cases:
  1. Basic EXTENDS operation - verify it completes without error
  2. Verify Dog.prototype.constructor is set to Animal
  3. Verify Dog.prototype.__proto__ is set to Animal.prototype

Expected output:
  EXTENDS test started
  Step 1: Creating constructors
  Step 2: Calling EXTENDS
  Step 3: Checking constructor property
  Step 4: Checking __proto__ property
  EXTENDS completed successfully
"""

import struct

# Create a minimal SWF7 file with comprehensive EXTENDS test
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # SWF 7 for ActionScript 2.0 features

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper functions to build actions
def push_string(s):
    """Create PUSH action for a string"""
    string_data = s.encode('latin1') + b'\x00'
    return struct.pack('<BHB', 0x96, len(string_data) + 1, 0) + string_data

def push_float(f):
    """Create PUSH action for a float"""
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', f)

# Action opcodes
ACTION_TRACE = bytes([0x26])
ACTION_INIT_OBJECT = bytes([0x43])
ACTION_DUPLICATE = bytes([0x4C])
ACTION_GET_VARIABLE = bytes([0x1C])
ACTION_SET_VARIABLE = bytes([0x1D])
ACTION_SET_MEMBER = bytes([0x4F])
ACTION_GET_MEMBER = bytes([0x4E])
ACTION_EXTENDS = bytes([0x69])
ACTION_EQUALS2 = bytes([0x49])
ACTION_STRICT_EQUALS = bytes([0x66])

# Build ActionScript bytecode
actions = b''

# Trace start message
actions += push_string('EXTENDS test started')
actions += ACTION_TRACE

actions += push_string('Step 1: Creating constructors')
actions += ACTION_TRACE

# ===================================================================
# Create "Animal" constructor object with prototype
# ===================================================================

# Create Animal prototype object
actions += push_float(0.0)  # Number of properties
actions += ACTION_INIT_OBJECT

# Store Animal prototype in variable "AnimalPrototype"
actions += ACTION_DUPLICATE
actions += push_string('AnimalPrototype')
actions += ACTION_SET_VARIABLE

# Create Animal constructor object
actions += push_float(0.0)
actions += ACTION_INIT_OBJECT

# Set prototype property on Animal object
actions += ACTION_DUPLICATE  # Duplicate Animal object

# Get the AnimalPrototype variable
actions += push_string('AnimalPrototype')
actions += ACTION_GET_VARIABLE

# Push property name "prototype"
actions += push_string('prototype')

# SetMember: Animal.prototype = AnimalProto_obj
actions += ACTION_SET_MEMBER

# Store Animal in variable
actions += push_string('Animal')
actions += ACTION_SET_VARIABLE

# ===================================================================
# Create "Dog" constructor object with prototype
# ===================================================================

# Create Dog prototype object
actions += push_float(0.0)
actions += ACTION_INIT_OBJECT

# Store Dog prototype
actions += ACTION_DUPLICATE
actions += push_string('DogPrototype')
actions += ACTION_SET_VARIABLE

# Create Dog constructor object
actions += push_float(0.0)
actions += ACTION_INIT_OBJECT

# Set prototype property on Dog object
actions += ACTION_DUPLICATE

# Get DogPrototype variable
actions += push_string('DogPrototype')
actions += ACTION_GET_VARIABLE

# Push "prototype"
actions += push_string('prototype')

# SetMember: Dog.prototype = DogProto_obj
actions += ACTION_SET_MEMBER

# Store Dog in variable
actions += push_string('Dog')
actions += ACTION_SET_VARIABLE

# ===================================================================
# Call EXTENDS to set up inheritance: Dog extends Animal
# ===================================================================

actions += push_string('Step 2: Calling EXTENDS')
actions += ACTION_TRACE

# Get Dog variable (subclass)
actions += push_string('Dog')
actions += ACTION_GET_VARIABLE

# Get Animal variable (superclass)
actions += push_string('Animal')
actions += ACTION_GET_VARIABLE

# EXTENDS opcode (0x69)
# Pops Animal (superclass), then Dog (subclass)
# Sets up Dog.prototype.__proto__ = Animal.prototype
# Sets up Dog.prototype.constructor = Animal
actions += ACTION_EXTENDS

# ===================================================================
# Test: Verify Dog.prototype.constructor points to Animal
# ===================================================================

actions += push_string('Step 3: Checking constructor property')
actions += ACTION_TRACE

# Get Dog.prototype.constructor
actions += push_string('Dog')
actions += ACTION_GET_VARIABLE
actions += push_string('prototype')
actions += ACTION_GET_MEMBER
actions += push_string('constructor')
actions += ACTION_GET_MEMBER

# Get Animal
actions += push_string('Animal')
actions += ACTION_GET_VARIABLE

# Compare with STRICT_EQUALS (should return 1 if same object)
actions += ACTION_STRICT_EQUALS

# Trace the result (will be 1 for true, 0 for false)
actions += ACTION_TRACE

# ===================================================================
# Test: Verify Dog.prototype.__proto__ points to Animal.prototype
# ===================================================================

actions += push_string('Step 4: Checking __proto__ property')
actions += ACTION_TRACE

# Get Dog.prototype.__proto__
actions += push_string('Dog')
actions += ACTION_GET_VARIABLE
actions += push_string('prototype')
actions += ACTION_GET_MEMBER
actions += push_string('__proto__')
actions += ACTION_GET_MEMBER

# Get Animal.prototype
actions += push_string('Animal')
actions += ACTION_GET_VARIABLE
actions += push_string('prototype')
actions += ACTION_GET_MEMBER

# Compare with STRICT_EQUALS
actions += ACTION_STRICT_EQUALS

# Trace the result
actions += ACTION_TRACE

# ===================================================================
# Success message
# ===================================================================

actions += push_string('EXTENDS completed successfully')
actions += ACTION_TRACE

# End action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test: EXTENDS opcode (0x69) - Property verification")
print("Expected output:")
print("  EXTENDS test started")
print("  Step 1: Creating constructors")
print("  Step 2: Calling EXTENDS")
print("  Step 3: Checking constructor property")
print("  1")
print("  Step 4: Checking __proto__ property")
print("  1")
print("  EXTENDS completed successfully")
