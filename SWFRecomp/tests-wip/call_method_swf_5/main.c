#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include necessary headers
#include <stackvalue.h>
#include <variables.h>
#include <action.h>
#include <object.h>

#define INITIAL_STACK_SIZE 8388608
#define INITIAL_SP INITIAL_STACK_SIZE

// Test Case 1: Simple method that returns a property value
// Expected: obj.getValue() returns 10
ActionVar func_getValue(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
    ActionVar result;
    result.type = ACTION_STACK_VALUE_F64;

    if (this_obj != NULL) {
        ASObject* obj = (ASObject*)this_obj;
        ActionVar* value_prop = getProperty(obj, "value", 5);
        if (value_prop != NULL && value_prop->type == ACTION_STACK_VALUE_F64) {
            result.data.numeric_value = value_prop->data.numeric_value;
            return result;
        }
    }

    // Return undefined if this is null or property not found
    result.type = ACTION_STACK_VALUE_UNDEFINED;
    result.data.numeric_value = 0;
    return result;
}

// Test Case 2: Method with arguments that performs addition
// Expected: obj.add(5, 3) returns 8
ActionVar func_add(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
    ActionVar result;
    result.type = ACTION_STACK_VALUE_F64;

    if (arg_count >= 2) {
        double a = 0, b = 0;

        if (args[0].type == ACTION_STACK_VALUE_F64) {
            a = VAL(double, &args[0].data.numeric_value);
        } else if (args[0].type == ACTION_STACK_VALUE_F32) {
            a = (double)VAL(float, &args[0].data.numeric_value);
        }

        if (args[1].type == ACTION_STACK_VALUE_F64) {
            b = VAL(double, &args[1].data.numeric_value);
        } else if (args[1].type == ACTION_STACK_VALUE_F32) {
            b = (double)VAL(float, &args[1].data.numeric_value);
        }

        VAL(double, &result.data.numeric_value) = a + b;
    } else {
        VAL(double, &result.data.numeric_value) = 0;
    }

    return result;
}

// Test Case 3: Method that accesses multiple properties via this
// Expected: obj.sum() returns 15 (this.x + this.y = 5 + 10)
ActionVar func_sum(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
    ActionVar result;
    result.type = ACTION_STACK_VALUE_F64;
    VAL(double, &result.data.numeric_value) = 0;

    if (this_obj != NULL) {
        ASObject* obj = (ASObject*)this_obj;
        double x = 0, y = 0;

        ActionVar* x_prop = getProperty(obj, "x", 1);
        if (x_prop != NULL && x_prop->type == ACTION_STACK_VALUE_F64) {
            x = VAL(double, &x_prop->data.numeric_value);
        }

        ActionVar* y_prop = getProperty(obj, "y", 1);
        if (y_prop != NULL && y_prop->type == ACTION_STACK_VALUE_F64) {
            y = VAL(double, &y_prop->data.numeric_value);
        }

        VAL(double, &result.data.numeric_value) = x + y;
    }

    return result;
}

int main() {
    printf("Starting ActionCallMethod test...\n");

    // Initialize variable map
    initMap();
    printf("Variable map initialized\n");

    // Initialize stack
    char* stack = (char*)malloc(INITIAL_STACK_SIZE);
    if (!stack) {
        fprintf(stderr, "Failed to allocate stack\n");
        return 1;
    }
    printf("Stack allocated\n");

    u32 sp_val = INITIAL_SP;
    u32* sp = &sp_val;

    char str_buffer[256];

    printf("Starting Test Case 1...\n");
    // Test Case 1: Call Simple Method
    // var obj = { value: 10, getValue: function() { return this.value; } };
    // trace(obj.getValue());

    // Create object with 2 properties
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 2.0;
    actionInitObject(stack, sp);

    // Store object reference in a variable
    ActionVar obj_var = {0};
    popVar(stack, sp, &obj_var);
    printf("Object created: type=%d, value=%lx\n", obj_var.type, obj_var.data.numeric_value);

    // Set property: obj.value = 10
    pushVar(stack, sp, &obj_var);
    PUSH_STR("value", 5);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 10.0;
    actionSetMember(stack, sp);

    // Define and set the getValue method
    actionDefineFunction2(stack, sp, "getValue", func_getValue, 0, 0, 0);
    ActionVar func_var;
    popVar(stack, sp, &func_var);

    pushVar(stack, sp, &obj_var);
    PUSH_STR("getValue", 8);
    pushVar(stack, sp, &func_var);
    actionSetMember(stack, sp);

    // Call obj.getValue() and trace result
    pushVar(stack, sp, &obj_var);
    PUSH_STR("getValue", 8);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 0.0;

    actionCallMethod(stack, sp, str_buffer);
    actionTrace(stack, sp);

    // Test Case 2: Call Method with Arguments
    // var obj = { add: function(a, b) { return a + b; } };
    // trace(obj.add(5, 3));

    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 1.0;
    actionInitObject(stack, sp);

    ActionVar obj2_var;
    popVar(stack, sp, &obj2_var);

    // Define and set the add method
    actionDefineFunction2(stack, sp, "add", func_add, 2, 0, 0);
    ActionVar func_add_var;
    popVar(stack, sp, &func_add_var);

    pushVar(stack, sp, &obj2_var);
    PUSH_STR("add", 3);
    pushVar(stack, sp, &func_add_var);
    actionSetMember(stack, sp);

    // Call obj.add(5, 3) and trace result
    pushVar(stack, sp, &obj2_var);
    PUSH_STR("add", 3);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 2.0;
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 5.0;
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 3.0;

    actionCallMethod(stack, sp, str_buffer);
    actionTrace(stack, sp);

    // Test Case 3: Method Accessing This
    // var obj = { x: 5, y: 10, sum: function() { return this.x + this.y; } };
    // trace(obj.sum());

    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 3.0;
    actionInitObject(stack, sp);

    ActionVar obj3_var;
    popVar(stack, sp, &obj3_var);

    // Set property: obj.x = 5
    pushVar(stack, sp, &obj3_var);
    PUSH_STR("x", 1);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 5.0;
    actionSetMember(stack, sp);

    // Set property: obj.y = 10
    pushVar(stack, sp, &obj3_var);
    PUSH_STR("y", 1);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 10.0;
    actionSetMember(stack, sp);

    // Define and set the sum method
    actionDefineFunction2(stack, sp, "sum", func_sum, 0, 0, 0);
    ActionVar func_sum_var;
    popVar(stack, sp, &func_sum_var);

    pushVar(stack, sp, &obj3_var);
    PUSH_STR("sum", 3);
    pushVar(stack, sp, &func_sum_var);
    actionSetMember(stack, sp);

    // Call obj.sum() and trace result
    pushVar(stack, sp, &obj3_var);
    PUSH_STR("sum", 3);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 0.0;

    actionCallMethod(stack, sp, str_buffer);
    actionTrace(stack, sp);

    // Test Case 4: Call Non-Existent Method
    // var obj = {};
    // trace(obj.nonExistent());

    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 0.0;
    actionInitObject(stack, sp);

    ActionVar obj4_var;
    popVar(stack, sp, &obj4_var);

    // Call obj.nonExistent() and trace result
    pushVar(stack, sp, &obj4_var);
    PUSH_STR("nonExistent", 11);
    PUSH(ACTION_STACK_VALUE_F64, 0);
    VAL(double, &STACK_TOP_VALUE) = 0.0;

    actionCallMethod(stack, sp, str_buffer);
    actionTrace(stack, sp);

    free(stack);
    return 0;
}
