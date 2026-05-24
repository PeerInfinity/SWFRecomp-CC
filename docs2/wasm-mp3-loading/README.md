# WASM MP3 loading demo

A small self-contained Emscripten demo showing three ways to feed an MP3
into a C runtime running in the browser, all converging on the same
in-memory `minimp3` decode + WebAudio playback.

Built as a reference for the discussion about how LittleCube's `Sound`
class (currently `mp3dec_ex_open(path)` + SDL3 audio) translates to the
web. None of the three methods require changes to the C-side `minimp3`
decode loop — only the "how do bytes get into memory" step differs.

## The three methods

| # | Method | C-side code | Web-specific glue |
|---|--------|-------------|-------------------|
| 1 | Bundled at build time  | plain `fopen("/assets/foo.mp3")` | `emcc --preload-file assets@/assets` |
| 2 | User-supplied file     | plain `fopen("/uploads/foo.mp3")` | JS `FileReader` → `FS.writeFile(path, bytes)` → `ccall("play_uploaded", …, [path])` |
| 3 | Remote URL (CDN, etc.) | `emscripten_fetch(url)` + decode from memory | `-s FETCH=1` at build time |

Methods 1 and 2 are byte-for-byte identical from C's perspective — both
read from MEMFS via `fopen`. Method 3 bypasses MEMFS and goes straight to
HTTP from C. For modding support, method 2 is the local-file path and
method 3 is the "fetch from GitHub Pages / mod manifest" path.

## Files

```
demo.c               C source — three load methods + minimp3 decode + extern js_play_pcm/js_log
minimp3.h            single-header MP3 decoder (lieff/minimp3, CC0)
library_audio.js     Emscripten library — implements js_play_pcm/js_log in JS-side WebAudio
index.html           three-button UI + Module init
build.sh             emcc invocation (sources emsdk_env.sh if emcc not on PATH)
assets/              three bundled test MP3s (method 1 picks via dropdown):
                       beat-mono.mp3    126 KB, 44.1 kHz mono,    8 s   (Emscripten test corpus)
                       beat-stereo.mp3  246 KB, 44.1 kHz stereo,  8 s   (Emscripten test corpus)
                       stereo8.mp3       22 KB,  8 kHz   stereo,  7 s   (Gnash test corpus, low-fi)
```

## Build

```bash
./build.sh
```

This sources `../../emsdk/emsdk_env.sh` if `emcc` isn't already on `PATH`.
Outputs `demo.js`, `demo.wasm`, `demo.data` next to `index.html`.

## Run

The browser refuses to load `.wasm` from `file://` URLs, so you need a
local HTTP server. Anything will do:

```bash
python3 -m http.server 8080
# then open http://localhost:8080/
```

You should see the three buttons. Each one logs to the on-page log and
the browser DevTools console.

## What to expect

- **Bundled**: instant playback — the `.data` sidecar was downloaded
  with the page so `fopen` reads from RAM. Pick from three clips via the
  dropdown: a clean drum-loop mono, the same loop in stereo, and a low-fi
  8 kHz stereo clip (handy for verifying the decode + WebAudio path
  handles legacy sample rates).
- **File picker**: pick any `.mp3` (the noise/click MP3s under
  `ruffle-tests/tests/swfs/avm1/*/{noise,sound,click}.mp3` are convenient
  test inputs). Decode happens on the main thread — for typical-sized
  files this is sub-second.
- **URL fetch**: by default fetches `assets/beat-mono.mp3` from the same
  server (so it works offline). Replace the URL with a CORS-enabled
  absolute URL to test "remote mod" semantics — e.g. a raw GitHub Pages
  link.

## Things this demo deliberately skips

- **IDBFS persistence.** Real modding would mount IndexedDB at
  `/uploads` and call `FS.syncfs(false)` after writing, so user mods
  survive page reloads. Two extra lines in `library_audio.js`.
- **AudioContext autoplay-gesture handling.** Because every method here
  is triggered by a user click, the AudioContext is allowed to start
  immediately. A real game whose audio begins before the user clicks
  needs an explicit `ctx.resume()` on the first interaction.
- **Streaming playback (`isStreaming`).** This demo decodes the full
  file before playing. Real streaming maps to the fetch Streams API
  (`response.body` is a `ReadableStream`) and decoding frames as they
  arrive.
- **SDL3 audio.** This demo uses WebAudio directly (smaller build, less
  setup). SDL3's Emscripten port works and routes to WebAudio internally,
  so all three load methods above transfer to the SDL3 setup unchanged —
  the only difference is `SDL_PutAudioStreamData(stream, pcm, bytes)` in
  place of the `AudioBufferSourceNode` plumbing in `library_audio.js`.
