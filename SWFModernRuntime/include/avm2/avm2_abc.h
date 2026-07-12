#ifndef AVM2_ABC_H
#define AVM2_ABC_H

// Static ABC data contract between the recompiler's C emitter
// (SWFRecomp/src/abc/abc_emit.cpp → RecompiledABC/) and the AVM2 runtime.
//
// The emitter lowers the verified IR's pool/table indices
// (SWFRecomp/include/abc/abc_ir.hpp) into these const tables; every index
// here is a direct index into the owning Avm2AbcFileData's arrays,
// INCLUDING the synthetic entry 0 ("any"/no value) that the parser gives
// every constant pool. Runtime-mutable state (script globals, init flags,
// realized classes) lives in the parallel Avm2AbcFileRt.

#include <stddef.h>
#include <stdint.h>

#include <avm2/avm2_value.h>

typedef struct Avm2AbcFileRt Avm2AbcFileRt;
typedef struct Avm2Class Avm2Class;
typedef struct Avm2ScopeChain Avm2ScopeChain;

// Namespace kinds: raw ABC values (abc_types.hpp NamespaceKind).
// Package (0x16) and Namespace (0x08) fold together as "public" during
// name matching, mirroring Ruffle namespace.rs is_public.
typedef struct Avm2AbcNamespace
{
	uint8_t kind;
	uint32_t name;  // string index
} Avm2AbcNamespace;

typedef struct Avm2AbcNsSet
{
	uint32_t count;
	const uint32_t* ns_indices;  // namespace indices
} Avm2AbcNsSet;

// Multiname kinds: raw ABC values (abc_types.hpp MultinameKind).
typedef struct Avm2AbcMultiname
{
	uint8_t kind;
	uint32_t ns;      // namespace index (QName/QNameA)
	uint32_t name;    // string index
	uint32_t ns_set;  // ns-set index (Multiname*/MultinameL*)
	// TypeName (0x1d): parameterized type, e.g. Vector.<int>.
	uint32_t base_type;            // multiname index of the base (Vector)
	uint32_t type_param_count;
	const uint32_t* type_params;   // multiname indices (0 = "any" → Vector.<*>)
} Avm2AbcMultiname;

// Slot/optional-parameter default value: raw ABC DefaultValueKind + a
// pool index whose pool depends on the kind (abc_types.hpp).
typedef struct Avm2AbcDefault
{
	uint8_t has_value;
	uint8_t kind;
	uint32_t index;
} Avm2AbcDefault;

// Trait kinds: raw ABC values (abc_types.hpp TraitKindType):
// 0 Slot, 1 Method, 2 Getter, 3 Setter, 4 Class, 5 Function, 6 Const.
typedef struct Avm2AbcTrait
{
	uint8_t kind;
	uint32_t name_mn;         // multiname index (QName)
	uint32_t slot_or_disp_id; // 0 = auto-assign
	uint32_t type_mn;         // multiname index (Slot/Const)
	uint32_t method_or_class; // method index (Method/Getter/Setter/Function) or class index (Class)
	Avm2AbcDefault value;     // Slot/Const initial value
} Avm2AbcTrait;

struct Avm2Activation;
typedef Avm2Value (*Avm2MethodFn)(struct Avm2Activation* act);

// Exception table entry, offsets resolved to op indices. Dispatch matches
// Ruffle activation.rs handle_err: op in [from_op, to_op), typed match by
// is_of_type (type_mn 0 = catch-all).
typedef struct Avm2AbcException
{
	uint32_t from_op;
	uint32_t to_op;
	uint32_t target_op;
	uint32_t type_mn;
	uint32_t variable_mn;
	uint8_t active;
} Avm2AbcException;

// Method flags: raw ABC values (abc_types.hpp MethodFlags).
enum
{
	AVM2_METHOD_NEED_ARGUMENTS = 1 << 0,
	AVM2_METHOD_NEED_ACTIVATION = 1 << 1,
	AVM2_METHOD_NEED_REST = 1 << 2,
	AVM2_METHOD_HAS_OPTIONAL = 1 << 3,
	AVM2_METHOD_IGNORE_REST = 1 << 4,
	AVM2_METHOD_NATIVE = 1 << 5,
};

typedef struct Avm2AbcMethodData
{
	Avm2MethodFn fn;         // NULL = no body (native / interface method)
	const char* debug_name;  // pool name, for diagnostics
	uint8_t flags;
	// Referenced by NewFunction / a Function trait (Ruffle is_function):
	// with an all-untyped default-free signature the method is "unchecked"
	// (missing args become undefined, extra args allowed).
	uint8_t is_function;
	uint32_t param_count;
	const uint32_t* param_types;      // param_count multiname indices (NULL if 0)
	const Avm2AbcDefault* optionals;  // param_count entries, trailing ones present (NULL if none)
	uint32_t return_type_mn;
	uint32_t body_trait_count;        // activation-object traits (method body traits)
	const Avm2AbcTrait* body_traits;
	uint32_t exception_count;
	const Avm2AbcException* exceptions;
} Avm2AbcMethodData;

enum
{
	AVM2_CLASS_FLAG_SEALED = 1 << 0,
	AVM2_CLASS_FLAG_FINAL = 1 << 1,
	AVM2_CLASS_FLAG_INTERFACE = 1 << 2,
};

typedef struct Avm2AbcClassData
{
	uint32_t name_mn;       // multiname index (QName)
	uint32_t super_mn;      // multiname index (0 = none: Object/interface)
	uint8_t flags;
	uint8_t has_protected_ns;
	uint32_t protected_ns;  // namespace index
	uint32_t interface_count;
	const uint32_t* interface_mns;  // multiname indices
	uint32_t instance_init; // method index
	uint32_t class_init;    // method index (static initializer)
	uint32_t instance_trait_count;
	const Avm2AbcTrait* instance_traits;
	uint32_t class_trait_count;
	const Avm2AbcTrait* class_traits;
} Avm2AbcClassData;

typedef struct Avm2AbcScriptData
{
	uint32_t init_method;  // method index
	uint32_t trait_count;
	const Avm2AbcTrait* traits;
} Avm2AbcScriptData;

typedef struct Avm2AbcFileData
{
	uint32_t int_count;
	const int32_t* ints;
	uint32_t uint_count;
	const uint32_t* uints;
	uint32_t double_count;
	const double* doubles;
	uint32_t string_count;
	const Avm2String* strings;
	uint32_t namespace_count;
	const Avm2AbcNamespace* namespaces;
	uint32_t ns_set_count;
	const Avm2AbcNsSet* ns_sets;
	uint32_t multiname_count;
	const Avm2AbcMultiname* multinames;
	uint32_t method_count;
	const Avm2AbcMethodData* methods;
	uint32_t class_count;
	const Avm2AbcClassData* classes;
	uint32_t script_count;
	const Avm2AbcScriptData* scripts;
} Avm2AbcFileData;

// SymbolClass (tag 76): char_id 0 = the root/main timeline class.
typedef struct Avm2SymbolClassBinding
{
	uint16_t char_id;
	const char* class_name;  // dotted ("test_fla.MainTimeline")
} Avm2SymbolClassBinding;

// Provided by the generated RecompiledABC/abc_registry.c:
extern const Avm2AbcFileData* const avm2_generated_abc_files[];
extern const uint32_t avm2_generated_abc_file_count;
extern const Avm2SymbolClassBinding avm2_generated_symbol_classes[];
extern const uint32_t avm2_generated_symbol_class_count;
extern const uint8_t avm2_generated_swf_version;

// ---------------------------------------------------------------------------
// Static timeline tables (Stage 5): emitted by the recompiler's
// abc_timeline.cpp second pass over the tag stream (AVM2 SWFs only, into
// RecompiledABC/abc_timeline.c). Mirrors Ruffle's static movie data; the
// AVM2 display tree consumes these directly — zero entanglement with the
// AVM1 tag.c runtime.
// ---------------------------------------------------------------------------

enum
{
	AVM2_TLOP_PLACE = 0,   // PlaceObject/2/3 (new character or modify/move)
	AVM2_TLOP_REMOVE = 1,  // RemoveObject/2
};

enum
{
	AVM2_TLF_HAS_CHAR = 1 << 0,
	AVM2_TLF_MOVE = 1 << 1,        // PlaceObject2 move flag
	AVM2_TLF_HAS_MATRIX = 1 << 2,
	AVM2_TLF_HAS_NAME = 1 << 3,
	AVM2_TLF_HAS_CLIP_DEPTH = 1 << 4,
	AVM2_TLF_HAS_RATIO = 1 << 5,
	AVM2_TLF_HAS_VISIBLE = 1 << 6,  // PlaceObject3 visible flag present
};

typedef struct Avm2TimelineOp
{
	uint8_t kind;    // AVM2_TLOP_*
	uint8_t flags;   // AVM2_TLF_*
	uint8_t visible; // valid when HAS_VISIBLE
	uint16_t char_id;
	uint16_t depth;
	uint16_t clip_depth;
	uint16_t ratio;
	const char* name;  // NULL unless HAS_NAME
	// Matrix (valid when HAS_MATRIX): scale/rot as f32, translate twips.
	float mtx_a, mtx_b, mtx_c, mtx_d;
	int32_t mtx_tx, mtx_ty;
} Avm2TimelineOp;

typedef struct Avm2FrameLabelData
{
	uint32_t frame;      // 0-based frame index
	const char* label;
} Avm2FrameLabelData;

typedef struct Avm2TimelineData
{
	uint16_t char_id;          // 0 = root/main timeline
	uint32_t frame_count;      // ShowFrame count (incl. a trailing partial frame)
	uint32_t declared_frames;  // header/DefineSprite frame count field
	const Avm2TimelineOp* ops;
	const uint32_t* frame_op_starts;  // frame_count + 1 entries into ops[]
	uint32_t label_count;
	const Avm2FrameLabelData* labels;
} Avm2TimelineData;

// Character dictionary entry (Define* tags): classification + bounds.
enum
{
	AVM2_CHAR_SHAPE = 0,
	AVM2_CHAR_SPRITE = 1,
	AVM2_CHAR_BUTTON = 2,
	AVM2_CHAR_TEXT = 3,      // DefineText/2 (static text)
	AVM2_CHAR_EDITTEXT = 4,  // DefineEditText
	AVM2_CHAR_BITMAP = 5,
	AVM2_CHAR_MORPHSHAPE = 6,
	AVM2_CHAR_VIDEO = 7,
	AVM2_CHAR_OTHER = 8,     // fonts, sounds, ... (not placeable)
};

typedef struct Avm2CharInfo
{
	uint16_t char_id;
	uint8_t kind;  // AVM2_CHAR_*
	// Self bounds in twips (shapes/texts; zero for sprites — computed from
	// children at runtime).
	int32_t xmin, xmax, ymin, ymax;
	// DefineEditText initial text (NULL when absent / not an EditText).
	const char* init_text;
} Avm2CharInfo;

// DefineEditText static data (Stage 6). Flags mirror the tag bit-for-bit
// where possible; raw_text is the tag's InitialText verbatim (HTML markup
// preserved when the html flag is set).
enum
{
	AVM2_ETF_WORD_WRAP = 1 << 0,
	AVM2_ETF_MULTILINE = 1 << 1,
	AVM2_ETF_PASSWORD = 1 << 2,
	AVM2_ETF_READ_ONLY = 1 << 3,
	AVM2_ETF_AUTO_SIZE = 1 << 4,
	AVM2_ETF_NO_SELECT = 1 << 5,
	AVM2_ETF_BORDER = 1 << 6,
	AVM2_ETF_WAS_STATIC = 1 << 7,
	AVM2_ETF_HTML = 1 << 8,
	AVM2_ETF_USE_OUTLINES = 1 << 9,
	AVM2_ETF_HAS_FONT = 1 << 10,
	AVM2_ETF_HAS_FONT_CLASS = 1 << 11,
	AVM2_ETF_HAS_TEXT_COLOR = 1 << 12,
	AVM2_ETF_HAS_MAX_LENGTH = 1 << 13,
	AVM2_ETF_HAS_LAYOUT = 1 << 14,
	AVM2_ETF_HAS_TEXT = 1 << 15,
};

typedef struct Avm2EditTextData
{
	uint16_t char_id;
	uint16_t flags;          // AVM2_ETF_*
	uint16_t font_id;        // meaningful when HAS_FONT
	const char* font_class;  // NULL unless HAS_FONT_CLASS
	uint16_t font_height;    // twips (HAS_FONT)
	uint32_t color_rgba;     // 0xRRGGBBAA (HAS_TEXT_COLOR)
	uint16_t max_length;     // HAS_MAX_LENGTH
	uint8_t align;           // 0 left, 1 right, 2 center, 3 justify (HAS_LAYOUT)
	uint16_t left_margin;    // twips (HAS_LAYOUT)
	uint16_t right_margin;   // twips (HAS_LAYOUT)
	uint16_t indent;         // twips (HAS_LAYOUT)
	int16_t leading;         // twips (HAS_LAYOUT)
	const char* variable_name;  // NULL when empty
	const char* raw_text;    // NULL unless HAS_TEXT
	// CSMTextSettings (tag 74) for this character, if present.
	uint8_t has_render_settings;
	uint8_t aa_advanced;     // UseFlashType != 0
	uint8_t grid_fit;        // 0 none, 1 pixel, 2 subpixel
	float cs_thickness, cs_sharpness;
} Avm2EditTextData;

// DefineFont2/3 measurement data (Stage 6): enough for the text layout
// engine (advances + code table + vertical metrics); glyph shapes are not
// parsed. Units are the font's EM square (1024 for DefineFont2, 20480 for
// DefineFont3).
typedef struct Avm2FontData
{
	uint16_t font_id;
	const char* name;
	uint8_t bold, italic;
	uint8_t has_layout;
	uint16_t em_square;      // 1024 (DefineFont2) or 20480 (DefineFont3)
	int32_t ascent, descent, leading;  // font units (has_layout)
	uint32_t glyph_count;
	const uint16_t* codes;   // glyph index -> character code
	const int16_t* advances; // glyph index -> advance, font units (has_layout)
} Avm2FontData;

// DefineSceneAndFrameLabelData (root timeline only).
typedef struct Avm2SceneData
{
	const char* name;
	uint32_t offset;  // 0-based start frame
} Avm2SceneData;

// DefineButton/2 state records (Stage-5 tranche 5).
typedef struct Avm2ButtonRecordData
{
	uint16_t char_id;
	uint16_t depth;
	uint8_t state_flags;  // bit0 up, bit1 over, bit2 down, bit3 hitTest
	uint8_t has_matrix;
	float mtx_a, mtx_b, mtx_c, mtx_d;
	int32_t mtx_tx, mtx_ty;
} Avm2ButtonRecordData;

typedef struct Avm2ButtonData
{
	uint16_t char_id;
	uint32_t record_count;
	const Avm2ButtonRecordData* records;
} Avm2ButtonData;

// Provided by the generated RecompiledABC/abc_timeline.c:
extern const Avm2TimelineData avm2_generated_timelines[];
extern const uint32_t avm2_generated_timeline_count;
extern const Avm2CharInfo avm2_generated_chars[];
extern const uint32_t avm2_generated_char_count;
extern const Avm2SceneData avm2_generated_scenes[];
extern const uint32_t avm2_generated_scene_count;
extern const Avm2ButtonData avm2_generated_buttons[];
extern const uint32_t avm2_generated_button_count;
extern const Avm2EditTextData avm2_generated_edittexts[];
extern const uint32_t avm2_generated_edittext_count;
extern const Avm2FontData avm2_generated_fonts[];
extern const uint32_t avm2_generated_font_count;
extern const int32_t avm2_generated_stage_rect[4];   // xmin xmax ymin ymax twips
extern const uint16_t avm2_generated_frame_rate;     // 8.8 fixed
extern const uint16_t avm2_generated_header_frames;  // header frame count
extern const uint32_t avm2_generated_bg_color;       // 0xRRGGBB (SetBackgroundColor)

// ---------------------------------------------------------------------------
// Runtime-mutable per-file state
// ---------------------------------------------------------------------------

enum
{
	AVM2_SCRIPT_UNINITIALIZED = 0,
	AVM2_SCRIPT_INITIALIZING = 1,
	AVM2_SCRIPT_INITIALIZED = 2,
};

struct Avm2AbcFileRt
{
	const Avm2AbcFileData* data;
	Avm2Context* ctx;
	Avm2Object** script_globals;  // one per script
	uint8_t* script_init_state;
	Avm2Class** classes;          // realized by NewClass; NULL until then
};

// Activation record passed to every emitted method body and native method.
typedef struct Avm2Activation
{
	Avm2Context* ctx;
	Avm2AbcFileRt* file;       // defining ABC file (NULL for pure natives)
	Avm2Class* bound_class;    // defining class (ConstructSuper); NULL for scripts
	Avm2ScopeChain* outer;     // captured outer scope chain (NULL = empty)
	Avm2Value this_val;
	const Avm2Value* args;
	uint32_t argc;
	Avm2Object* callee;        // function object being invoked (arguments.callee); may be NULL
} Avm2Activation;

#endif // AVM2_ABC_H
