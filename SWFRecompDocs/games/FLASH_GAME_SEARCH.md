# Open Source Flash Game Search

Date: 2026-03-08

## Goal

Find an open source AVM1 (ActionScript 1/2) Flash game that uses only features already implemented in SWFRecomp-CC, to serve as a real-world integration test and demo.

## Requirements

The game must:
- Use AVM1 (SWF version ≤8, ActionScript 1 or 2)
- Not require audio playback (Sound class stubs exist but no actual audio)
- Not require loadMovie (external SWF loading)
- Not require BitmapData manipulation
- Not require SharedObject (local storage)
- Not require network connectivity (LoadVars, XMLSocket, etc.)
- Work with our implemented graphics pipeline (shapes, sprites, buttons, text fields, transforms)

## Sources Searched

### GitHub Repositories with SWF Files
- **[Games-From-Flash/swf](https://github.com/Games-From-Flash/swf)** — 51 Flash games (SWF files directly available). Mixed AS versions. Includes: Pacman, Snake, Tetris, Checkers, Minesweeper, Bloxorz, Super Mario Flash, The Impossible Quiz, and more.
- **[TylerGlaiel/GlaielGamesOldFlashSources](https://github.com/TylerGlaiel/GlaielGamesOldFlashSources)** — AS2 games with FLA source (Blockslide, Nutcracker, etc.). No compiled SWFs; requires Flash IDE.
- **[AthulDilip/AS2-Platform-Game](https://github.com/AthulDilip/AS2-Platform-Game)**, **[AS2-Mario-Game](https://github.com/AthulDilip/AS2-Mario-Game)**, **[AS2-Racing-Game](https://github.com/AthulDilip/AS2-Racing-Game)** — AS2 games, FLA only (no SWF).

### Archive.org Collections
- **[FlashGameVault SWF v4-5](https://archive.org/details/swf4-5_flashgamevault)** — 367 SWF files, all SWF version 4-5 (guaranteed AS1). Simplest possible games. Best bulk source.
- **[MostFunGames SWF v4-5](https://archive.org/details/swf4-5_mostfungames)** — Similar collection of early Flash games.
- **[ArmorGames SWF Archive](https://archive.org/details/armorgames)** — Large collection, mixed AS versions.

### Tutorials (AS2, with source)
- Envato Tuts+ Snake Game (AS2)
- Flash Game Tuts Brick Breaker (AS2)
- These have source but may require Flash IDE to compile.

## Games Evaluated

Six games were downloaded from Games-From-Flash/swf and recompiled:

| Game | SWF Version | Size | Recompiles | Scripts | Blockers |
|------|-------------|------|------------|---------|----------|
| **Snake** | 5 | 10KB | Yes | 22 | **None** |
| Tetris | 6 | 14KB | Yes | 20 | SharedObject, LoadVars |
| Minesweeper | 6 | 29KB | Yes | 59 | JPEG3 images (tag 35 fails) |
| Pacman | 6 | 43KB | Yes | 66 | LoadVars, stopSounds, Color |
| Checkers | 6 | 136KB | Yes | ? | Sound/attachSound |
| Bloxorz | 8 | 2.3MB | Yes | ? | Not fully investigated |

### Detailed Feature Analysis

#### Snake (RECOMMENDED)
- **Origin**: Neave Games (neave.com)
- **Resolution**: 320x320 @ 24fps, 57 frames
- **ActionScript features used**:
  - `actionCloneSprite` / `actionRemoveSprite` — snake body segments
  - `actionSetTarget` — timeline MC targeting
  - `actionSetProperty` / `actionGetProperty` — _x, _y, _visible
  - `actionRandomNumber` — food placement
  - `actionGotoFrame` / `actionPlay` / `actionStop` — game state transitions
  - `actionGetVariable` / `actionSetVariable` — score, level tracking
  - `actionCallMethod` — gotoAndPlay on "Sound" MC (timeline sound, not Sound class)
  - `actionStringAdd`, `actionMultiply`, `actionSubtract`, etc. — basic math/string ops
  - `actionGetURL` — link to neave.com (harmless, just a "more games" button)
- **What it does NOT use**: Sound class, SharedObject, LoadVars, BitmapData, loadMovie, XML, Date, Array methods, DefineFunction2, try/catch, classes
- **Verdict**: Perfect match for our feature set

#### Tetris
- Uses `SharedObject` for saving high scores (we don't implement)
- Uses `LoadVars` for posting scores to server (we don't implement)
- Uses `clearInterval` (we do implement)
- Uses `attachMovie`, `Key`, `Math`, `Stage` (all implemented)
- Could potentially work if SharedObject/LoadVars calls fail gracefully

#### Pacman
- Uses `LoadVars` for high scores
- Uses `actionStopSounds` (stub exists)
- Uses `Color` class (implemented)
- Sound-related MovieClip names suggest it expects audio playback
- More complex (66 scripts)

#### Checkers
- Uses `Sound` class with `attachSound` (not fully implemented)
- Uses `startDrag`/`endDrag` (implemented)
- Uses `actionTrace` (implemented)
- AI logic with `Math.abs`, `Math.atan` (implemented)
- Might work silently without sound

#### Minesweeper
- Has JPEG3 bitmap images (tag 35 / DefineBitsJPEG3) — recompiler warns but continues
- Uses DefineFontInfo2 (tag 62) — not implemented
- May have rendering issues due to bitmap dependency

## What Was Done

1. Downloaded 6 game SWFs from Games-From-Flash/swf
2. Verified all are AVM1 (SWF versions 5-8)
3. Successfully recompiled all 6 through SWFRecomp
4. Analyzed ActionScript features used by each game
5. Set up Snake as a test at `SWFRecomp/tests/snake/`
6. **Snake compiles natively** (NO_GRAPHICS mode) — confirmed working
7. WASM graphics build fails due to pre-existing runtime issue (see below)

## Blocking Issue: Graphics Build

WASM graphics builds (`--graphics` flag) are currently broken for ALL tests (not just games). The error is:

```
action.c:27777:12: error: no member named 'ng_textfield_idx' in 'struct MovieClip'
```

This is a pre-existing issue where `action.c` references `ng_textfield_idx` but the MovieClip struct in `swf.h` (graphics mode) doesn't define it. The NO_GRAPHICS `swf_headless.h` likely has different struct definitions. This needs to be fixed before any graphics WASM builds work.

There are also ~20 other errors in the graphics build (likely cascading from struct mismatches).

## Next Steps

1. **Fix graphics build** — Resolve `ng_textfield_idx` and other struct mismatches between graphics and no-graphics modes
2. **Build Snake as WASM with graphics** — Once the build is fixed, test Snake in a browser
3. **Test runtime behavior** — Verify game logic works (keyboard input, sprite cloning, collision detection, frame navigation)
4. **Try more games** — Once Snake works, try Tetris (next simplest) and Checkers
5. **Explore FlashGameVault archive** — 367 SWF v4-5 games for more simple candidates
6. **Consider tag 17 (DefineSound)** — Snake has DefineSound tags that are currently skipped. The game works without them but adding sound support would make it more complete.

## File Locations

- Snake SWF + test setup: `SWFRecomp/tests/snake/`
- Downloaded game SWFs (temporary): `/tmp/flash_games/`
- Games-From-Flash repo: https://github.com/Games-From-Flash/swf
