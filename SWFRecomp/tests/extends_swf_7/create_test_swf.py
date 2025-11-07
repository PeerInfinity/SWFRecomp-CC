#!/usr/bin/env python3
"""
Test script for EXTENDS opcode (0x69)

This creates a simple SWF that tests the ActionScript 2.0 extends keyword
for setting up prototype-based inheritance between classes.

The EXTENDS opcode sets up the prototype chain between two constructor functions.

Test: Basic EXTENDS operation
  1. Create two objects to act as constructor functions
  2. Set up their prototype properties
  3. Call EXTENDS to establish inheritance
  4. Trace success message

Expected output:
  EXTENDS test started
  EXTENDS completed successfully
"""

import struct

# Create a minimal SWF7 file with EXTENDS test
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # SWF 7 for ActionScript 2.0 features

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Trace start message
string_start = b'EXTENDS test started\x00'
action_push_start = struct.pack('<BHB', 0x96, len(string_start) + 1, 0)  # PUSH string
action_push_start += string_start
actions += action_push_start
action_trace = bytes([0x26])  # TRACE (0x26)
actions += action_trace

# Create "Animal" constructor object (simulated with InitObject)
# In a real implementation, this would be a DefineFunction
# For now, we'll create a simple object to act as a constructor

# Create prototype object for Animal
# Push properties: none for now
action_push_0 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float 0
action_push_0 += struct.pack('<f', 0.0)
actions += action_push_0
action_init_object = bytes([0x43])  # INIT_OBJECT (0x43)
actions += action_init_object

# Store Animal prototype in variable "AnimalPrototype"
action_duplicate = bytes([0x4C])  # DUPLICATE (0x4C)
actions += action_duplicate
string_animal_proto = b'AnimalPrototype\x00'
action_push_animal_proto = struct.pack('<BHB', 0x96, len(string_animal_proto) + 1, 0)
action_push_animal_proto += string_animal_proto
actions += action_push_animal_proto
action_set_variable = bytes([0x1D])  # SET_VARIABLE (0x1D)
actions += action_set_variable

# Create Animal constructor object
actions += action_push_0
actions += action_init_object

# Set prototype property on Animal object
# Stack: [Animal_obj]
actions += action_duplicate  # [Animal_obj, Animal_obj]

# Get the AnimalPrototype variable
string_animal_proto_get = b'AnimalPrototype\x00'
action_push_animal_proto_get = struct.pack('<BHB', 0x96, len(string_animal_proto_get) + 1, 0)
action_push_animal_proto_get += string_animal_proto_get
actions += action_push_animal_proto_get
action_get_variable = bytes([0x1C])  # GET_VARIABLE (0x1C)
actions += action_get_variable  # [Animal_obj, Animal_obj, AnimalProto_obj]

# Push property name "prototype"
string_prototype = b'prototype\x00'
action_push_prototype = struct.pack('<BHB', 0x96, len(string_prototype) + 1, 0)
action_push_prototype += string_prototype
actions += action_push_prototype  # [Animal_obj, Animal_obj, AnimalProto_obj, "prototype"]

# SetMember: Animal.prototype = AnimalProto_obj
action_set_member = bytes([0x4F])  # SET_MEMBER (0x4F)
actions += action_set_member  # [Animal_obj]

# Store Animal in variable
string_animal = b'Animal\x00'
action_push_animal = struct.pack('<BHB', 0x96, len(string_animal) + 1, 0)
action_push_animal += string_animal
actions += action_push_animal
actions += action_set_variable

# Create "Dog" constructor object (same process)
# Create prototype for Dog
actions += action_push_0
actions += action_init_object

# Store Dog prototype
actions += action_duplicate
string_dog_proto = b'DogPrototype\x00'
action_push_dog_proto = struct.pack('<BHB', 0x96, len(string_dog_proto) + 1, 0)
action_push_dog_proto += string_dog_proto
actions += action_push_dog_proto
actions += action_set_variable

# Create Dog constructor object
actions += action_push_0
actions += action_init_object

# Set prototype property on Dog object
actions += action_duplicate

# Get DogPrototype variable
string_dog_proto_get = b'DogPrototype\x00'
action_push_dog_proto_get = struct.pack('<BHB', 0x96, len(string_dog_proto_get) + 1, 0)
action_push_dog_proto_get += string_dog_proto_get
actions += action_push_dog_proto_get
actions += action_get_variable

# Push "prototype"
actions += action_push_prototype

# SetMember: Dog.prototype = DogProto_obj
actions += action_set_member

# Store Dog in variable
string_dog = b'Dog\x00'
action_push_dog = struct.pack('<BHB', 0x96, len(string_dog) + 1, 0)
action_push_dog += string_dog
actions += action_push_dog
actions += action_set_variable

# Now call EXTENDS to set up inheritance: Dog extends Animal
# Stack order: Push Dog (subclass), then Animal (superclass)

# Get Dog variable
string_dog_get = b'Dog\x00'
action_push_dog_get = struct.pack('<BHB', 0x96, len(string_dog_get) + 1, 0)
action_push_dog_get += string_dog_get
actions += action_push_dog_get
actions += action_get_variable  # [Dog_obj]

# Get Animal variable
string_animal_get = b'Animal\x00'
action_push_animal_get = struct.pack('<BHB', 0x96, len(string_animal_get) + 1, 0)
action_push_animal_get += string_animal_get
actions += action_push_animal_get
actions += action_get_variable  # [Dog_obj, Animal_obj]

# EXTENDS opcode (0x69)
# Pops Animal (superclass), then Dog (subclass)
# Sets up Dog.prototype.__proto__ = Animal.prototype
# Sets up Dog.prototype.constructor = Animal
action_extends = bytes([0x69])  # EXTENDS (0x69)
actions += action_extends

# Trace success message
string_success = b'EXTENDS completed successfully\x00'
action_push_success = struct.pack('<BHB', 0x96, len(string_success) + 1, 0)
action_push_success += string_success
actions += action_push_success
actions += action_trace

# End action
action_end = bytes([0x00])
actions += action_end

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
print("Test: EXTENDS opcode (0x69) - Set up prototype chain")
print("Expected output:")
print("  EXTENDS test started")
print("  EXTENDS completed successfully")
