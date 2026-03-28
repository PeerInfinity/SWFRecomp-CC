# Sound ID3 Tag Parsing Plan
<!-- TESTS: sound_id3, sound_id3_prop -->

<!-- PLAN_META
id: SOUND_ID3
status: not_started
phases:
  - id: 1
    name: "ID3v1 parser"
    status: not_started
  - id: 2
    name: "ID3v2 parser"
    status: not_started
  - id: 3
    name: "ID3 object construction"
    status: not_started
  - id: 4
    name: "onID3 callback dispatch"
    status: not_started
  - id: 5
    name: "Integration with loadSound"
    status: not_started
dependencies:
  - plan: SOUND_LOADING
    phases: [1]
    type: requires
    reason: "loadSound implementation needed for ID3 parsing"
blockers: []
-->

Last updated: 2026-03-27

## Status: NOT STARTED — Blocked on ID3 parser implementation

### Test Summary

| Test | Lines | Current | Status | Notes |
|------|-------|---------|--------|-------|
| sound_id3 | 633 | 11/633 (2%) | ignored | Full ID3v1/v2 tag parsing + onID3 callback |
| sound_id3_prop | 138 | 1/138 (1%) | ignored | ID3 property access patterns |

### Expected Behavior

**sound_id3** (633 lines, 1 tick):

The test loads `id3.mp3` (with ID3 tags) and `noid3.mp3` (without), then:

1. Before load: `sound.id3 === undefined` (strict equality returns `true`)
2. `loadSound("id3.mp3", false)` triggers load
3. `onID3` callback fires with the Sound instance
4. Inside onID3: `sound.id3` is an object with:
   - **ID3v2 frame IDs**: TCON (genre), TYER (year), TORY, TOFN, TOPE, TOAL, TMED, TLEN,
     TIT3, TIT2, TCOM, TPE2, TPOS, TRCK, TALB, TPE1, COMM
   - **Lowercase aliases**: genre, year, track, songname, comment, album, artist
   - COMM frame may return as an object array with multiple entries
   - All accessible via bracket notation (`id3["TCON"]`, `id3.genre`)
5. For `noid3.mp3`: `sound.id3` remains undefined, onID3 may not fire

**sound_id3_prop** (138 lines, 1 tick):

Tests `sound.id3` property access at different points in the load lifecycle across
multiple "Place" configurations. Verifies that ID3 data becomes available after
onID3 fires and persists across subsequent accesses.

### Current Infrastructure

- `sound.id3` property: Not implemented (returns undefined via generic property access)
- `onID3` callback: Not dispatched
- ID3 parser: Does not exist anywhere in the codebase
- MP3 files available as test assets: `id3.mp3`, `noid3.mp3` in test directories
- `minimp3.h` decodes audio but does **not** parse ID3 tags (skips them)

### What Needs to Be Built

#### 1. ID3v1 Parser (~50 lines)

ID3v1 is the simplest format — last 128 bytes of the MP3 file:
```
Offset  Length  Field
0       3       "TAG" signature
3       30      Title
33      30      Artist
63      30      Album
93      4       Year
97      30      Comment (28 bytes + track byte if ID3v1.1)
127     1       Genre (byte index into genre table)
```

#### 2. ID3v2 Parser (~200 lines)

ID3v2 is at the start of the MP3 file. Header format:
```
Offset  Length  Field
0       3       "ID3" signature
3       2       Version (major.minor)
5       1       Flags
6       4       Size (syncsafe integer)
10+     var     Frames
```

Each frame:
```
Offset  Length  Field
0       4       Frame ID (e.g., "TIT2", "TPE1", "TALB")
4       4       Size
8       2       Flags
10      1       Text encoding (0=Latin1, 1=UTF16, 2=UTF16BE, 3=UTF8)
11+     var     Data (text string)
```

**Required frames**: TCON, TYER, TORY, TOFN, TOPE, TOAL, TMED, TLEN, TIT3, TIT2,
TCOM, TPE2, TPOS, TRCK, TALB, TPE1, COMM

#### 3. ID3 Object Construction (~60 lines)

After parsing, create an ASObject with:
- Frame ID properties: `id3["TIT2"] = "Song Title"`
- Lowercase aliases: `id3.songname = "Song Title"`, `id3.artist = "Artist Name"`

**Alias mapping**:
| ID3v2 Frame | Lowercase Alias |
|-------------|----------------|
| TIT2 | songname |
| TPE1 | artist |
| TALB | album |
| TYER | year |
| TCON | genre |
| TRCK | track |
| COMM | comment |

#### 4. onID3 Callback Dispatch (~20 lines)

After ID3 parsing completes, fire `onID3` on the Sound instance:
1. Look up `onID3` property on the Sound object
2. If function, call with the Sound as `this`
3. Set `sound.id3` property to the constructed ID3 object before calling

#### 5. Integration with loadSound (~10 lines)

In the `loadSound()` implementation (from SOUND_LOADING_PLAN.md):
1. Before MP3 decoding, scan for ID3v1 (last 128 bytes) and ID3v2 (first bytes) headers
2. Parse tags, construct ID3 object, set on Sound instance
3. Dispatch onID3 callback
4. Then proceed with MP3 decoding (minimp3 skips ID3 headers automatically)

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Sound prototype | `action.c` | 22930-23066 |
| loadSound stub | `action.c` | 23063 |
| minimp3 decoder | `SWFModernRuntime/src/audio/audio.c` | (skips ID3) |
| Test MP3 files | `ruffle-tests/tests/swfs/avm1/sound_id3/` | id3.mp3, noid3.mp3 |

### Dependencies

- **Requires SOUND_LOADING_PLAN.md** Phase 1 (loadSound with embedded data)
- ID3 parser is self-contained (no external libraries needed)

### Why Blocked

The ID3v2 parser is a non-trivial new component (~200 lines) that needs to handle:
- Syncsafe integer encoding
- Multiple text encodings (Latin1, UTF-16, UTF-8)
- COMM frame special structure (language code + description + text)
- Robust parsing of potentially malformed headers

This is a focused, self-contained implementation task but requires careful binary parsing.

### Estimated Complexity

Medium-high. ~340 lines total:
- ID3v1 parser: ~50 lines
- ID3v2 parser: ~200 lines
- ID3 object construction: ~60 lines
- onID3 dispatch + integration: ~30 lines
