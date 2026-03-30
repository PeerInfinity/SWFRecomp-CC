#pragma once

#include <stackvalue.h>

// Forward declaration for o1heap
typedef struct O1HeapInstance O1HeapInstance;

#define HEAP_SIZE 1024*1024*1024  // 1 GB

// Forward declaration for SWFAppContext (needed for frame_func typedef)
typedef struct SWFAppContext SWFAppContext;

// Frame function now takes app_context parameter
typedef void (*frame_func)(SWFAppContext* app_context);

extern frame_func frame_funcs[];

// Button action: condition bitmask + function to call on matching transition
typedef struct ButtonAction {
	u16 condition;        // bitmask of triggering transitions
	frame_func action;    // function to call
} ButtonAction;

// Clip action: event bitmask + function to call on matching event
typedef struct ClipAction {
	u32 event_flags;      // bitmask of triggering events
	frame_func action;    // function to call
} ClipAction;

// Character type enum for shapes, text, sprites, and buttons
typedef enum
{
	CHAR_TYPE_SHAPE,
	CHAR_TYPE_MORPH_SHAPE,
	CHAR_TYPE_TEXT,
	CHAR_TYPE_SPRITE,
	CHAR_TYPE_BUTTON,
} CharacterType;

#define INITIAL_DICTIONARY_CAPACITY 8192  // Increased to support per-movie char_id offsetting (1000 per child SWF)
#define INITIAL_DISPLAYLIST_CAPACITY 1024

// Clip event flag bits (SWF spec)
#define CLIP_EVENT_LOAD         0x00001
#define CLIP_EVENT_ENTER_FRAME  0x00002
#define CLIP_EVENT_UNLOAD       0x00004
#define CLIP_EVENT_MOUSE_MOVE   0x00008
#define CLIP_EVENT_MOUSE_DOWN   0x00010
#define CLIP_EVENT_MOUSE_UP     0x00020
#define CLIP_EVENT_KEY_DOWN     0x00040
#define CLIP_EVENT_KEY_UP       0x00080
#define CLIP_EVENT_DATA         0x00100
#define CLIP_EVENT_INITIALIZE   0x00200
#define CLIP_EVENT_PRESS        0x00400
#define CLIP_EVENT_RELEASE      0x00800
#define CLIP_EVENT_RELEASE_OUTSIDE 0x01000
#define CLIP_EVENT_ROLL_OVER    0x02000
#define CLIP_EVENT_ROLL_OUT     0x04000
#define CLIP_EVENT_DRAG_OVER    0x08000
#define CLIP_EVENT_DRAG_OUT     0x10000
#define CLIP_EVENT_KEY_PRESS    0x20000
#define CLIP_EVENT_CONSTRUCT    0x40000

typedef struct Character
{
	CharacterType type;
	union
	{
		// DefineShape
		struct
		{
			size_t shape_offset;
			size_t size;
		};
		// DefineMorphShape
		struct
		{
			size_t morph_start_offset;
			size_t morph_start_size;
			size_t morph_end_offset;
			size_t morph_color_start;
			size_t morph_color_count;
		};
		// DefineText
		struct
		{
			size_t text_start;
			size_t text_size;
			u32 transform_start;
			u32 cxform_id;
		};
		// DefineSprite
		struct
		{
			frame_func* sprite_frame_funcs;
			size_t sprite_frame_count;
			size_t sprite_byte_size;
		};
		// DefineButton
		struct
		{
			frame_func* button_state_funcs;  // [up, over, down]
			size_t button_hit_char_id;       // character ID for hit-test shape
			u32 button_hit_transform_id;     // transform for hit-test shape
			ButtonAction* button_actions;    // condition→action pairs
			size_t button_action_count;
		};
	};
} Character;

typedef struct DisplayObject
{
	size_t char_id;
	u32 transform_id;
	u32 cxform_id;
	u32 has_cxform;
	u16 clip_depth;
	u16 ratio;
	u8 button_state;       // 0=idle, 1=over, 2=down, 3=outDown (CHAR_TYPE_BUTTON)
	u8 button_prev_state;  // previous frame's state (for transition detection)
	u8 sticky_button_state; // preserved state across remove+re-place (same char)
	size_t sticky_char_id;  // char_id that sticky_button_state belongs to
	u8 blend_mode;         // 0=normal (default), see SWF spec blend modes
	// Per-sprite persistent display list (for multi-frame sprites)
	struct DisplayObject* sprite_display_list;
	size_t sprite_max_depth;
	size_t sprite_dl_capacity;
	size_t sprite_current_frame;
	u8 sprite_is_playing;         // 0=stopped, 1=playing (default 1)
	int sprite_manual_next_frame;  // pending manual frame nav
	size_t sprite_next_frame;      // target frame
	char* instance_name;           // from PlaceObject2 HasName (or NULL)
	u8 instance_name_owned;        // 1 if instance_name was malloc'd (auto-assigned), 0 if pointer to static string
	// Clip actions (PlaceObject2 HasClipActions)
	ClipAction* clip_actions;
	size_t clip_action_count;
	// Accumulated clip actions from a prior Remove that was immediately followed by a Re-place
	// at the same depth in the same frame. Fired before clip_actions on the next removal.
	ClipAction* accumulated_clip_actions;
	size_t accumulated_clip_action_count;
	// Visual filter (PlaceObject3 FilterList)
	u8 filter_type;       // 0=none, 1=blur, 2=drop_shadow, 3=glow, 4=bevel
	u8 filter_quality;    // blur passes (1-3)
	u8 filter_flags;      // inner/knockout/compositeSource
	double filter_blur_x;
	double filter_blur_y;
	double filter_color_r;
	double filter_color_g;
	double filter_color_b;
	double filter_color_a;
	double filter_strength;
	double filter_angle;
	double filter_distance;
	// Bevel highlight color (shadow color uses filter_color_*)
	double filter_highlight_r;
	double filter_highlight_g;
	double filter_highlight_b;
	double filter_highlight_a;
	// Scriptable color transform override (mutable at runtime by ActionScript)
	double cx_ra, cx_ga, cx_ba, cx_aa;  // multipliers (percentage: 100.0 = normal)
	double cx_rb, cx_gb, cx_bb, cx_ab;  // addends (0..255 range, 0 = normal)
	int cx_overridden;                   // 1 if cx_* fields override cxform_data[]
	// Timeline tracking
	u8 sprite_needs_init;   // 1 if frame_0 needs to run this tick (NO_GRAPHICS)
	u8 depth_swapped;       // 1 if moved here by swapDepths (skip timeline modifies)
	size_t placed_at_frame; // frame index when this object was placed
	size_t place_gen;       // monotonic generation counter for same-frame detection
	// Clip event interaction state
	u8 clip_mc_pressed;     // 1 if CLIP_EVENT_PRESS was fired for this clip (awaiting RELEASE/RELEASE_OUTSIDE)
	u8 enterframe_eligible; // 1 if AS2 onEnterFrame should fire this tick (set by init/advance, cleared after dispatch)
	u8 constructor_invoked; // 1 if registered class constructor was already invoked during eager init
	u8 sprite_initialized;  // 0=not init, 1=init'd this tick, 2=init'd on previous tick (for per-tick EnterFrame gating)
	// Cached transform values (populated at placement time for correct bounds on child SWFs)
	float place_a, place_b, place_c, place_d, place_tx, place_ty;
	// Child movie transform data override (set during placement when g_active_transform_data != NULL)
	float (*child_transform_data)[16];
} DisplayObject;

typedef struct KeyState {
	uint8_t down[256];     // 1 if key currently held (indexed by ASCII/keyCode)
	uint8_t toggled[256];  // toggle state for lock keys (CapsLock=20, NumLock=144, ScrollLock=145)
	int last_key_down;     // keyCode of most recently pressed key (-1 if none)
	int last_key_ascii;    // ASCII value of last key press (for Key.getAscii())
} KeyState;

typedef struct MouseState {
	float stage_x;      // Mouse X in twips (stage coordinates)
	float stage_y;      // Mouse Y in twips
	int button_down;    // 1 if left mouse button is held
	int clicked;        // 1 if button was pressed this frame (edge)
	int released;       // 1 if button was released this frame (edge)
	int moved;          // 1 if mouse moved this frame (edge)
} MouseState;

// Macros for stack access via app_context
#define STACK (app_context->stack)
#define SP (app_context->sp)
#define OLDSP (app_context->oldSP)

typedef struct SWFAppContext
{
	// Stack management (moved from globals)
	char* stack;
	u32 sp;
	u32 oldSP;

	frame_func* frame_funcs;
	size_t frame_count;  // Local addition - kept for compatibility
	u16 fps;

	// Shape/transform data (available in all modes for hit testing)
	char* shape_data;
	size_t shape_data_size;
	char* transform_data;
	size_t transform_data_size;

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
	int width;
	int height;

	const float* stage_to_ndc;

	size_t bitmap_count;
	size_t bitmap_highest_w;
	size_t bitmap_highest_h;

	char* color_data;
	size_t color_data_size;
	char* uninv_mat_data;
	size_t uninv_mat_data_size;
	char* gradient_data;
	size_t gradient_data_size;
	char* bitmap_data;
	size_t bitmap_data_size;

	// Font/Text data (from upstream)
	u32* glyph_data;
	size_t glyph_data_size;
	u32* text_data;
	size_t text_data_size;
	char* cxform_data;
	size_t cxform_data_size;
	char* morph_end_shape_data;
	size_t morph_end_shape_data_size;
	char* morph_end_color_data;
	size_t morph_end_color_data_size;

	void* audio_ctx;  // AudioContext* (opaque to avoid header dependency)
#endif

	// Input state (works in both graphics and NO_GRAPHICS modes)
	MouseState mouse;
	KeyState keys;

	// Heap management fields
	O1HeapInstance* heap_instance;
	char* heap;
	size_t heap_size;
	size_t heap_full_size;
	size_t heap_current_size;
	int heap_inited;

	// String ID support (from upstream)
	size_t max_string_id;

	// UTF-16 string cache (indexed by string_id, lazily populated)
	uint16_t** str_cache;
	u32* str_cache_len;
} SWFAppContext;

#ifndef DYNAMIC_GUEST
extern int quit_swf;
#endif
extern int is_playing;
extern size_t current_frame;
extern size_t next_frame;
extern int manual_next_frame;

// Global frame access for ActionCall opcode
extern frame_func* g_frame_funcs;
extern size_t g_frame_count;

// Drag state tracking (works in both graphics and NO_GRAPHICS modes)
extern int is_dragging;         // 1 if a sprite is being dragged, 0 otherwise
extern char* dragged_target;    // Name of the target being dragged (or NULL)
// Virtual drag position: registration point of dragged/last-dragged clip (twips).
// Updated on mouse move while dragging; persists after stopDrag for PRESS hit-testing.
extern float g_drag_virt_x;
extern float g_drag_virt_y;
// Name of the most recently dragged clip (persists after stopDrag for PRESS hit-testing).
extern char g_drag_target_name[256];

extern Character* dictionary;

extern DisplayObject* display_list;
extern size_t max_depth;

// Movie entry for pre-compiled child SWFs (multi-SWF / loadMovie support)
typedef struct MovieEntry {
	const char* filename;              // "target.swf"
	frame_func* frame_funcs;           // child's frame function array
	void (*init_func)(SWFAppContext*); // child's tagInit function
	u16 swf_version;
	u16 frame_count;
	u16 stage_width;
	u16 stage_height;
	u32 file_size;                     // SWF file size in bytes (for onLoadProgress)
	u8 movie_id;                       // 0 = main SWF, 1+ = child SWFs (for per-movie export isolation)
	float (*transform_data_ptr)[16];   // pointer to child SWF's transform_data (NULL = use main SWF's)
} MovieEntry;

// Find a pre-compiled movie entry by filename (defined in movie_registry.c when HAS_CHILD_MOVIES)
MovieEntry* findMovieEntry(const char* filename);

// Data file entry for loadVariables pre-bundled data
typedef struct DataFileEntry {
	const char* filename;
	const char* content;
	int content_length;
} DataFileEntry;

// Find a pre-bundled data file by filename (defined in data_registry.c when HAS_DATA_FILES)
DataFileEntry* findDataFile(const char* filename);

void swfStart(SWFAppContext* app_context);