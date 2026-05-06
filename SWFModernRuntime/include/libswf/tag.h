#pragma once

#include <common.h>
#include <swf.h>

// Core tag functions - always available
void tagInit(SWFAppContext* app_context);
// Dispatch button key-press conditions for a given key code.
// Called from swf_core.c after delivering EV_KEY_DOWN.
int dispatch_button_key_actions(SWFAppContext* app_context, int key_code);
// Fire button DoAction conditions for a specific transition on a MC.
// transition_mask: 0x0004 = press, 0x0008 = release
void ng_simulateButtonTransition(SWFAppContext* app_context, void* mc, int transition_mask);
// Set button_state on the display object for a button MC (for Tab virtual hover).
void ng_setButtonDisplayState(void* mc, u8 state);
// Simulate a button press+release on a specific MC (for keyboard focus activation).
void ng_simulateButtonPressRelease(SWFAppContext* app_context, void* mc);
// Run button hit-test + state machine + action dispatch for current mouse state.
// In NO_GRAPHICS mode called per mouse event; in graphics mode called from tagShowFrame.
int ng_update_button_states(SWFAppContext* app_context);
#ifdef NO_GRAPHICS
// Dispatch CLIP_EVENT_PRESS for all sprites whose hit area contains the mouse.
// Called from swf_core.c on EV_MOUSE_DOWN_LEFT.
void dispatch_clip_event_press(SWFAppContext* app_context);
// Dispatch CLIP_EVENT_RELEASE for sprites that had PRESS fired (clip_mc_pressed=1).
// Called from swf_core.c on EV_MOUSE_UP_LEFT.
void dispatch_clip_event_release(SWFAppContext* app_context);
// Dispatch CLIP_EVENT_ROLL_OVER/ROLL_OUT/DRAG_OVER/DRAG_OUT on hit-area transitions.
// Called from swf_core.c on EV_MOUSE_MOVE (and EV_MOUSE_DOWN/UP for button-state edges).
void dispatch_clip_event_roll(SWFAppContext* app_context);
// Dispatch a generic clip event flag (CLIP_EVENT_MOUSE_DOWN/UP/MOVE, KEY_DOWN/UP)
// to ALL clips in the display list (global events, no hit-test).
void dispatch_clip_event_flag(SWFAppContext* app_context, uint32_t flag);
// Compute the _droptarget slash-path for a point (in stage twips), skipping skip_name.
// Writes result to out_path (at most out_size-1 chars + NUL). Returns 1 if found, 0 if not.
int ng_compute_droptarget(float stage_x_twips, float stage_y_twips,
    const char* skip_name, char* out_path, size_t out_size);
#endif
void tagSetBackgroundColor(u8 red, u8 green, u8 blue);
void tagShowFrame(SWFAppContext* app_context);
#ifdef HEADLESS_GRAPHICS
void tagRerenderFrame(SWFAppContext* app_context);
#endif
void tagFlushPendingEnterFrame(SWFAppContext* app_context);

// Tag functions needed by both graphics and trace (NO_GRAPHICS) builds.
void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax);
void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
    size_t shape_offset, size_t shape_size,
    size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax,
    s32 end_bounds_xmin, s32 end_bounds_xmax, s32 end_bounds_ymin, s32 end_bounds_ymax);
void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id, s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax);
void tagDefineEditTextProps(SWFAppContext* app_context, size_t char_id,
    const char* plain_text, const char* raw_html_text, u32 text_color,
    u16 font_id, u16 font_height, s16 max_length,
    u8 align, u16 left_margin, u16 right_margin, s16 indent, s16 leading,
    const char* variable_name, u16 flags,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax);
void tagCSMTextSettings(size_t text_id, const char* anti_alias_type, const char* grid_fit_type, float thickness, float sharpness);
void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth);
void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio);
void tagPlaceObject2RatioWithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio, ClipAction* clip_actions, size_t clip_action_count);
void tagReplaceObject2RatioWithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio,
    ClipAction* old_clip_actions, size_t old_clip_action_count,
    ClipAction* new_clip_actions, size_t new_clip_action_count);
void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count);
// Attach clip actions to a display entry that was already placed (e.g. by tagPlaceObject2Ratio).
void tagSetClipActions(SWFAppContext* app_context, size_t depth, ClipAction* clip_actions, size_t clip_action_count);
void tagPlaceObject3(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u8 blend_mode);
void tagSetFilter(SWFAppContext* app_context, size_t depth,
    u8 type, double blur_x, double blur_y, u8 quality, u8 flags,
    double r, double g, double b, double a, double strength,
    double angle, double distance);
void tagSetFilterHighlight(SWFAppContext* app_context, size_t depth,
    double r, double g, double b, double a);
void tagSetFilterColorMatrix(SWFAppContext* app_context, size_t depth, const float* matrix20);
void tagSetFilterConvolution(SWFAppContext* app_context, size_t depth,
    u8 matrixX, u8 matrixY, const float* matrix, float divisor, float bias,
    u8 preserve_alpha, u8 clamp, u8 def_r, u8 def_g, u8 def_b, u8 def_a);
void tagSetFilterGradient(SWFAppContext* app_context, size_t depth,
    u8 type, u8 count, const u32* colors, const float* alphas, const u8* ratios,
    float blur_x, float blur_y, float angle, float distance, float strength,
    u8 quality, u8 flags);
// Extended filter data accessor (returns pointer to static data or NULL)
typedef struct ExtFilterData {
    u8 type;          // 5=convolution, 6=colormatrix, 7=gradientglow, 8=gradientbevel
    float cm_matrix[20];
    u8 conv_mx, conv_my;
    float conv_matrix[25];
    float conv_divisor, conv_bias;
    u8 conv_preserve_alpha, conv_clamp;
    u8 conv_color_r, conv_color_g, conv_color_b, conv_color_a;
    u8 grad_count;
    u32 grad_colors[16];
    float grad_alphas[16];
    u8 grad_ratios[16];
    float blur_x, blur_y, angle, distance, strength;
    u8 quality, flags;
} ExtFilterData;
const ExtFilterData* ng_getExtFilterData(size_t entry_idx);

// Multi-filter list: stores ALL SWF-authored filters per display entry
typedef struct FilterListEntry {
    u8 type;  // 1=blur, 2=dropshadow, 3=glow, 4=bevel, 5=conv, 6=cm, 7=gradglow, 8=gradbevel
    // Common fields (types 1-4, 7-8)
    double blur_x, blur_y;
    u8 quality, flags;
    double color_r, color_g, color_b, color_a;
    double strength, angle, distance;
    double highlight_r, highlight_g, highlight_b, highlight_a;
    // ColorMatrix (type 6)
    float cm_matrix[20];
    // Convolution (type 5)
    u8 conv_mx, conv_my;
    float conv_matrix[25];
    float conv_divisor, conv_bias;
    u8 conv_preserve_alpha, conv_clamp;
    u8 conv_color_r, conv_color_g, conv_color_b, conv_color_a;
    // Gradient (types 7, 8)
    u8 grad_count;
    u32 grad_colors[16];
    float grad_alphas[16];
    u8 grad_ratios[16];
} FilterListEntry;

#define MAX_FILTER_LIST_SIZE 16
typedef struct FilterListData {
    size_t depth;
    u8 count;
    FilterListEntry entries[MAX_FILTER_LIST_SIZE];
} FilterListData;

void tagBeginFilterList(SWFAppContext* app_context, size_t depth, u8 count);
void tagAddSimpleFilter(SWFAppContext* app_context, size_t depth,
    u8 type, double blur_x, double blur_y, u8 quality, u8 flags,
    double r, double g, double b, double a, double strength,
    double angle, double distance);
void tagAddSimpleFilterHighlight(SWFAppContext* app_context, size_t depth,
    double hr, double hg, double hb, double ha);
void tagAddColorMatrixFilter(SWFAppContext* app_context, size_t depth, const float* matrix20);
void tagAddConvolutionFilter(SWFAppContext* app_context, size_t depth,
    u8 matrixX, u8 matrixY, const float* matrix, float divisor, float bias,
    u8 preserve_alpha, u8 clamp, u8 def_r, u8 def_g, u8 def_b, u8 def_a);
void tagAddGradientFilter(SWFAppContext* app_context, size_t depth,
    u8 type, u8 count, const u32* colors, const float* alphas, const u8* ratios,
    float blur_x, float blur_y, float angle, float distance, float strength,
    u8 quality, u8 flags);
void tagEndFilterList(SWFAppContext* app_context, size_t depth);
const FilterListData* ng_getFilterListData(size_t entry_idx);
void tagSetInstanceName(SWFAppContext* app_context, size_t depth, const char* name);
void tagRemoveObject(SWFAppContext* app_context, size_t depth);
void tagRemoveObject2(SWFAppContext* app_context, size_t depth);
void tagDefineSpriteEx(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count, size_t byte_size);
// Backwards-compatible macro: old 4-arg calls get byte_size=0
#define tagDefineSprite_5(ctx, cid, fn, fc, bs) tagDefineSpriteEx(ctx, cid, fn, fc, bs)
#define tagDefineSprite_4(ctx, cid, fn, fc)     tagDefineSpriteEx(ctx, cid, fn, fc, 0)
#define tagDefineSprite_GET(_1, _2, _3, _4, _5, NAME, ...) NAME
#define tagDefineSprite(...) tagDefineSprite_GET(__VA_ARGS__, tagDefineSprite_5, tagDefineSprite_4)(__VA_ARGS__)
void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs, size_t hit_char_id, u32 hit_transform_id, ButtonAction* actions, size_t action_count);
void defineBitmap(size_t offset, size_t size, u32 width, u32 height, u16 char_id);
void finalizeBitmaps();
void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
    u8 format, u8 rate, u8 sample_size, u8 stereo,
    u32 sample_count, const u8* data, size_t data_size);
void tagStartSound(SWFAppContext* app_context, u16 sound_id,
    int stop, u32 loop_count, u32 in_point, u32 out_point);
void tagSoundStreamHead(SWFAppContext* app_context,
    u8 format, u8 rate, u8 sample_size, u8 stereo,
    u16 avg_sample_count);
void tagSoundStreamBlock(SWFAppContext* app_context,
    const u8* data, size_t data_size);
void tagStopAllSounds(SWFAppContext* app_context);
void tagScriptLimits(u16 max_recursion, u16 timeout);
void tagDefineFontInfo(SWFAppContext* app_context, u16 font_id, const char* name, int bold, int italic);
void tagDefineFontMetrics(SWFAppContext* app_context, u16 font_id,
    s16 ascent, s16 descent, s16 leading, int em_square,
    const u16* code_table, const s16* advance_table, size_t glyph_count);
void tagDefineFontGlyphBase(u16 font_id, size_t glyph_base);
void tagDefineVideoStream(SWFAppContext* app_context, u16 char_id);
void tagRegisterExport(SWFAppContext* app_context, const char* name, size_t char_id);
void tagImportCharacter(SWFAppContext* app_context, size_t local_char_id, const char* export_name);

// Run a DoInitAction script, guarded by once-per-character-id.
// Used for DoInitAction tags inside DefineSprite definitions.
void tagDoInitActionGuarded(SWFAppContext* app_context, size_t char_id, frame_func action);

// Forward declaration (defined in actionmodern/action.h)
typedef struct MovieClip MovieClip;

// Frame label entry for label→frame mapping
typedef struct {
	const char* label;
	size_t frame;
} FrameLabelEntry;

// Register per-sprite frame labels (called from tagInit after tagDefineSprite)
void tagSetSpriteLabels(size_t char_id, FrameLabelEntry* labels, size_t count);
// Find a frame label in a sprite's label table. Returns 0-based frame or -1 if not found.
int ng_findSpriteLabelFrame(size_t char_id, const char* label);

// Per-sprite per-frame placement metadata. One entry per PlaceObject2/3 (and
// RemoveObject/2) inside the sprite's frame body. Used by the runtime to
// compute survives_rewind on sprite loop-back, mirroring Ruffle's run_goto.
typedef struct {
	u16 depth;
	u16 char_id;       // 0 means "Modify" (PlaceObject2 with no character)
	u16 ratio;
	u8  is_remove;     // 1 for RemoveObject/RemoveObject2 entries; 0 for places
	u8  has_clip_actions;
} FramePlacement;

// Register per-sprite per-frame placement table. frame_starts has length
// frame_count+1 (cumulative offsets into placements; final entry = total).
void tagSetSpritePlacements(u16 sprite_id, FramePlacement* placements,
                            u16* frame_starts, u16 frame_count);

// Lookup helper: returns pointer to first placement of frame `frame` for
// sprite `sprite_id`, and writes the count to *out_count. Returns NULL and
// sets *out_count = 0 if no table is registered or the frame is out of range.
const FramePlacement* ng_sprite_frame_placements(u16 sprite_id, u16 frame, u16* out_count);
// Navigate a MovieClip's sprite to a given 0-based frame.
// Returns 1 if sprite found and navigated, 0 if not found.
int ng_gotoFrameByMC(SWFAppContext* app_context, MovieClip* mc, u16 frame, int play);
// Get the character ID for a MovieClip's display entry.
size_t ng_getCharIdByMC(MovieClip* mc);
// Get the DefineSprite tag data size for a sprite character.
size_t ng_getSpriteByteSize(size_t char_id);

// Functions needed by action.c / tag.c in all build modes (NO_GRAPHICS, HEADLESS, GRAPHICS).
// Implementations live in tag_stubs.c (NO_GRAPHICS/HEADLESS) or swf.c stubs (GRAPHICS).
u16 ng_findFontIdByName(const char* name);
void ng_getTextExtent(u16 font_id, double font_size_px, const char* text, size_t text_len,
    double width_px, double* out_ascent, double* out_descent,
    double* out_width, double* out_height, double* out_tf_height, double* out_tf_width);
size_t ng_lookupExport(const char* name);
size_t ng_lookupExportForMovie(const char* name, u8 movie_id);
int ng_lookupExportVersion(const char* name);
int ng_lookupExportVersionForMovie(const char* name, u8 movie_id);
int32_t ng_getSoundDuration(u16 char_id);
int ng_getBitmapMetadata(u16 char_id, size_t* out_offset, size_t* out_size, u32* out_width, u32* out_height);
void ng_registerBitmapMetadata(u16 char_id, size_t offset, size_t size, u32 width, u32 height);
extern u8 g_current_movie_id;
void ng_on_place_object2(SWFAppContext* app_context, size_t depth, size_t char_id);
void ng_on_remove_object(SWFAppContext* app_context, size_t depth);
size_t ng_findDisplayEntryByName(const char* name);
int ng_getDisplayEntryFilterData(size_t idx, u8* type, float* blur_x, float* blur_y,
    u8* quality, u8* flags, float* r, float* g, float* b, float* a,
    float* strength, float* angle, float* distance,
    float* hr, float* hg, float* hb, float* ha);

// Currently-executing sprite DisplayObject (set by advance_sprite_frames in NO_GRAPHICS,
// or defined as dummy in swf.c for GRAPHICS mode). Used by action.c in all modes.
extern DisplayObject* g_current_sprite_obj;

// NO_GRAPHICS helpers for sprite timeline control from action.c
#ifdef NO_GRAPHICS
// Advance sprite timelines (replaces old ng_advanceSprites; called by swf_core.c)
void advance_sprite_frames(SWFAppContext* app_context);
// Advance only nested sprites within root-level sprites (deferred recursion).
// Call after advance_sprite_frames and the root frame script to match Ruffle's
// execution order: root-level sprites → root → nested children.
void advance_nested_sprite_frames(SWFAppContext* app_context);
// Returns 1 if any multi-frame sprite at root level is still playing
int hasPlayingSprites(void);
// Returns 1 if any initialized sprite has CLIP_EVENT_ENTER_FRAME clip actions
int hasClipEnterFrameHandlers(void);

int ng_isInsideSprite(void);
void ng_stopCurrentSprite(void);
void ng_playCurrentSprite(void);

// Root DL swap for inline catch-up from sprite init context
int ng_isInsideSpriteInit(void);
void ng_bumpSpriteInitDepth(void);
void ng_unbumpSpriteInitDepth(void);
int ng_swapToRootDL(DisplayObject** saved_dl, size_t* saved_max, size_t* saved_cap);
void ng_restoreFromRootDL(DisplayObject* saved_dl, size_t saved_max, size_t saved_cap);
void ng_gotoFrameCurrentSprite(u16 frame);
size_t ng_getSpriteFrameCount(void);
size_t ng_findDisplayEntryByName(const char* name);
// Find a display entry at the given SWF depth that is a direct child of root.
// Returns: 0=not found, 1=non-sprite (shape/text), 2=sprite (name written to out_name)
int ng_findRootChildAtSWFDepth(size_t swf_depth, char* out_name, size_t out_name_size);
size_t ng_findChildEntryDepth(const char* parent_name, const char* child_name);
void ng_updateDisplayDepth(const char* name, int new_as_depth);
void ng_swapDisplayDepths(const char* name1, const char* name2);
void ng_renameDisplayEntry(const char* old_name, const char* new_name);
void ng_display_clear_after(SWFAppContext* app_context, size_t target_frame);
int ng_isSpriteAtDepth(size_t depth);
int ng_isButtonAtDepth(size_t depth);
int ng_isTextFieldAtDepth(size_t depth);
const char* ng_getTextFieldInitialText(size_t depth);
u32 ng_getTextFieldColor(size_t depth);
u32 ng_getTextFieldColorByIdx(int idx);
int ng_getTextFieldIdx(size_t depth);
int ng_getCharTextfieldIdx(size_t char_id);
u16 ng_getTextFieldFlags(int tf_idx);
u16 ng_getTextFieldFontId(int tf_idx);
u16 ng_getTextFieldFontHeight(int tf_idx);
s16 ng_getTextFieldMaxLength(int tf_idx);
u8 ng_getTextFieldAlign(int tf_idx);
u16 ng_getTextFieldLeftMargin(int tf_idx);
u16 ng_getTextFieldRightMargin(int tf_idx);
s16 ng_getTextFieldIndent(int tf_idx);
s16 ng_getTextFieldLeading(int tf_idx);
const char* ng_getTextFieldVariableName(int tf_idx);
void ng_getTextFieldBounds(int tf_idx, s32* xmin, s32* xmax, s32* ymin, s32* ymax);
const char* ng_getTextFieldRawHtml(int tf_idx);
const char* ng_getTextFieldInitialTextByIdx(int tf_idx);
const char* ng_getFontName(u16 font_id);
const char* ng_getFontNameSWFDefined(u16 font_id);
int ng_getFontBold(u16 font_id);
int ng_getFontItalic(u16 font_id);
int ng_getTransformId(size_t depth, u32* out_id);
int ng_getTransformXY(size_t depth, float* out_x, float* out_y);
int ng_getTransformXY_d(size_t depth, double* out_x, double* out_y);
int ng_getTransformScaleRotation(size_t depth, float* out_xscale, float* out_yscale, float* out_rotation);
int ng_getColorTransform(const char* name, double* ra, double* ga, double* ba, double* aa,
                          double* rb, double* gb, double* bb, double* ab);
int ng_setColorTransform(const char* name, double ra, double ga, double ba, double aa,
                          double rb, double gb, double bb, double ab);
#ifdef NO_GRAPHICS
// Set only the alpha multiplier (cx_aa) on a display list entry. Used for _alpha ↔ Color sync.
void ng_setCTAlpha(size_t depth, double aa);
#endif
int ng_getCharBounds(size_t char_id, s32* out_xmin, s32* out_xmax, s32* out_ymin, s32* out_ymax);
// Compute union of child bounds in a sprite's display list, in LOCAL twips.
// Accounts for child transforms (scale, translation). Only available in NO_GRAPHICS builds.
int sprite_content_bounds_twips(DisplayObject* dl, size_t dl_max,
    float* xmin_out, float* xmax_out, float* ymin_out, float* ymax_out);
int ng_getCharBoundsForRatio(size_t char_id, u16 ratio,
    s32* out_xmin, s32* out_xmax, s32* out_ymin, s32* out_ymax);
// Compute content bounds (union of child bounds in pixels) for a display entry.
// entry_idx = (size_t)-1 for root-level children. Returns 1 if any bounds found, 0 if empty.
int ng_getDisplayEntryBounds(size_t entry_idx,
    float* out_xmin_px, float* out_xmax_px, float* out_ymin_px, float* out_ymax_px);
// Find display entry index by instance name. Returns (size_t)-1 if not found.
size_t ng_findDisplayEntryIdx(const char* name);
// Find display entry index by name AND parent display index. parent_idx=(size_t)-1 for root-level.
size_t ng_findDisplayEntryIdxWithParent(const char* name, size_t parent_idx);
// Get matrix components from a display entry (column-major SWF format). Returns 1 if found, 0 if not.
int ng_getMatrixFromEntry(size_t entry_idx, double* out_a, double* out_b, double* out_c, double* out_d, double* out_tx, double* out_ty);
// Get/set color transform on a display entry by index. Returns 1 if found, 0 if not.
int ng_getCTFromEntry(size_t entry_idx, double* ra, double* ga, double* ba, double* aa, double* rb, double* gb, double* bb, double* ab);
int ng_setCTOnEntry(size_t entry_idx, double ra, double ga, double ba, double aa, double rb, double gb, double bb, double ab);
// TextField variable binding — called from tag_stubs.c at placement time
void actionInitTextFieldVariable(SWFAppContext* app_context, const char* var_name, const char* init_text);
// Rename a cached MovieClip when tagSetInstanceName updates a sprite's display entry
void actionRenameMovieClip(const char* old_name, const char* new_name);
// Enumerate child instance names for a MovieClip (for for-in enumeration)
// callback receives (name, name_len, user_data) for each child
void ng_enumerateChildren(const char* parent_name, void (*callback)(const char* name, u32 name_len, void* user_data), void* user_data);
// Phase 1e: yield names of children removed in the most recent button-state
// transition. button_dobj is the button's DisplayObject; if it doesn't match
// the most recent transitioned button, no callbacks fire.
void ng_iterateTransientButtonChildren(void* button_dobj, void (*callback)(const char* name, u32 name_len, void* user_data), void* user_data);
// Check if a tag-placed display entry at the given root depth is scriptable (sprite/button/textfield)
int ng_isScriptableAtDepth(size_t depth);
// Clone a tag-placed sprite to target_name at AS depth. Returns clone MC, or NULL if non-scriptable/not found.
MovieClip* ng_cloneSprite(SWFAppContext* app_context, const char* source_name, const char* target_name, int depth);
// Clone a script-created MovieClip (not in ng_display) to target_name at AS depth.
MovieClip* ng_cloneSpriteFromMC(SWFAppContext* app_context, MovieClip* src_mc, const char* target_name, int depth);
// duplicateMovieClip clone: stores at SWF depth (as_depth+16384), no variable registration, no onLoad.
MovieClip* ng_duplicateMovieClip(SWFAppContext* app_context, const char* source_name, const char* target_name, int as_depth);

// Active transform data pointer — swapped to child SWF's array during child movie init.
// Defined in tag.c (NO_GRAPHICS builds only). NULL = use main SWF's transform_data.
extern float (*g_active_transform_data)[16];

#endif // NO_GRAPHICS (temporarily close for shared declarations below)

// --- Shared ng_* declarations (from ng_shared.c, always compiled) ---
// Register a child movie's transform data for sprite frame execution.
void ng_registerMovieTransformData(u8 movie_id, float (*td)[16]);

// Callbacks from tag.c → ng_shared.c supplemental registries (all build modes)
void ng_record_char_bounds(size_t char_id, s32 xmin, s32 xmax, s32 ymin, s32 ymax);
void ng_record_morph_end_bounds(size_t char_id, s32 xmin, s32 xmax, s32 ymin, s32 ymax);
// Record that a shape uses non-zero winding rule (DefineShape4 UsesFillWindingRule flag)
void ng_record_char_winding(size_t char_id);
// Record vector path data for a shape (for path-based hit testing)
void ng_record_char_path(size_t char_id, size_t path_offset, size_t path_size);
// Record interleaved morph path data (for interpolated hit testing)
void ng_record_morph_path(size_t char_id, size_t path_offset, size_t path_size);

#ifdef NO_GRAPHICS // reopen for remaining NO_GRAPHICS-only declarations
// Shape-accurate point-in-shape test for a display list.
// Walks the display list recursively; for leaf shapes, tests the test point against triangles.
// ma..mty is the accumulated parent matrix (twips space).
// test_x/test_y are the test point in twips.
// Returns: 1 = hit, 0 = miss.
int ng_hitTestShapeFromDL(DisplayObject* dl, size_t dl_max,
    double ma, double mb, double mc, double md, double mtx, double mty,
    double test_x, double test_y);
void ng_record_button(size_t char_id);
void ng_record_textfield_props(SWFAppContext* app_context, size_t char_id,
    const char* plain_text, const char* raw_html_text, u32 text_color,
    u16 font_id, u16 font_height, s16 max_length,
    u8 align, u16 left_margin, u16 right_margin, s16 indent, s16 leading,
    const char* variable_name, u16 flags,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax);
void ng_record_csm(size_t text_id, const char* anti_alias_type, const char* grid_fit_type,
    float thickness, float sharpness);
void ng_record_font(SWFAppContext* app_context, u16 font_id, const char* name, int bold, int italic);
void ng_record_font_metrics(SWFAppContext* app_context, u16 font_id,
    s16 ascent, s16 descent, s16 leading, int em_square,
    const u16* code_table, const s16* advance_table, size_t glyph_count);
void ng_record_font_glyph_base(u16 font_id, size_t glyph_base);
int ng_find_font_with_metrics(u16 font_id);
int ng_font_find_glyph(int font_idx, u16 code_point);
size_t ng_font_get_glyph_base(int font_idx);
int ng_font_get_metrics(int font_idx, s16* ascent, s16* descent, int* em_square);
s16 ng_font_glyph_advance_by_idx(int font_idx, int glyph_idx);
void ng_setTabStops(const int* stops_twips, int count, u16 font_height);
void ng_clearTabStops(void);
int ng_getCharIndexAtPoint(int tf_idx, float local_x_px, float local_y_px,
                           const char* text, size_t text_len);
int ng_computeTextWidth(u16 font_id, u16 font_height, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips, int align,
    int letter_spacing_twips);
int ng_computeTextHeight(u16 font_id, u16 font_height, s16 leading_twips, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips);
int ng_computeTextLineCount(u16 font_id, u16 font_height, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips);
int ng_computeVisibleLines(u16 font_id, u16 font_height, s16 leading_twips, float field_height_pixels);
void ng_computeScrollMixedFont(u16 font_id, u16 base_font_height, s16 leading_twips,
    const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips,
    float field_height_pixels, int scroll,
    const u32* run_starts, const u32* run_lengths, const u16* run_font_heights, int run_count,
    int* out_maxscroll, int* out_bottomscroll, int* out_text_height_twips);
// ng_findFontIdByName, ng_getTextExtent, ng_lookupExport, ng_getSoundDuration
// are declared above (outside #ifdef NO_GRAPHICS) since action.c needs them in all modes.
void ng_record_video(SWFAppContext* app_context, u16 char_id);
int ng_isVideoChar(size_t char_id);
// Attach a library symbol by char_id. Returns created MC, or NULL if not sprite.
MovieClip* ng_attachMovie(SWFAppContext* app_context, size_t char_id, const char* new_name, int as_depth, MovieClip* parent);
// Called after tagPlaceObject2 places an object (handles auto-naming, MC creation, textfield init)
void ng_on_place_object2(SWFAppContext* app_context, size_t depth, size_t char_id);
// Called before tagRemoveObject clears an object (handles MC invalidation, cleanup)
void ng_on_remove_object(SWFAppContext* app_context, size_t depth);
// Reclaim auto-instance counter slot if auto_name was the last assigned name
void ng_try_reclaim_auto_instance_name(const char* auto_name);
// Fire queued onLoad events for duplicated clips (called from tagShowFrame)
void ng_fire_pending_loads(SWFAppContext* app_context);
// Fire deferred init scripts for attachMovie clips (called from tagShowFrame)
void ng_fire_pending_attach_inits(SWFAppContext* app_context);
// Queue INIT/CONSTRUCT/LOAD clip events for a placement or clone (mirrors tagPlaceObject2).
void ng_queue_placement_clip_events(SWFAppContext* app_context, size_t depth);
// Queue UNLOAD clip-action callbacks for a slot (mirrors tagRemoveObject2).
void ng_queue_slot_unload_events(SWFAppContext* app_context, size_t depth, MovieClip* mc);
#endif
