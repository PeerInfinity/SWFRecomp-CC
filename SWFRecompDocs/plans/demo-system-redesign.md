# Demo System Redesign Plan

## Overview

Replace the current static HTML-per-test demo system with a dynamic single-page
demo loader (`demo.html`) backed by a generated `catalog.json` manifest. The new
system supports metadata display from `test_info.json`, optional Ruffle side-by-side
comparison using original `test.swf` files, and a JS-driven index page with opcode
coverage data from `opcode-index.json`.

## Current Architecture

- Each test builds its own `index.html` from `index_template.html` or
  `index_template_graphics.html` via sed substitution of `{{TEST_NAME}}`
- `deploy_example.sh` copies `.wasm`, `.js`, and `index.html` to `docs/examples/<test>/`
- `generate_examples_index.sh` uses awk to inject demo cards into `docs/index.html`
- `.demo_type` marker files (`trace` or `graphics`) guide card generation

## New Architecture

```
docs/
├── index.html              # Static shell + JS fetching catalog/opcode data
├── demo.html               # Dynamic demo loader (?test=name&compare=true)
├── catalog.json            # Generated manifest of all deployed tests
├── opcode-index.json       # Copy of repo-root opcode-index.json
├── favicon.svg
└── examples/
    ├── trace_swf_4/
    │   ├── trace_swf_4.wasm
    │   ├── trace_swf_4.js
    │   ├── test.swf            (for Ruffle comparison)
    │   ├── test_info.json      (test metadata)
    │   └── index.html          (redirect stub → demo.html?test=trace_swf_4)
    └── graphics/
        └── three_boxes/
            ├── three_boxes.wasm
            ├── three_boxes.js
            ├── test.swf
            ├── test_info.json
            └── index.html      (redirect stub)
```

---

## Phase 1: Data Pipeline

### 1a. deploy_example.sh

After copying `.wasm`, `.js`, and `index.html`, conditionally copy:
- `test.swf` from the test source directory
- `test_info.json` from the test source directory

### 1b. generate_examples_index.sh

Add a function to scan deployed examples and produce `catalog.json`:
- Read each test's `test_info.json` and `.demo_type`
- Include: id, name, type, path, js_file, wasm_file, has_swf, metadata from test_info
- Include excluded tests from `excluded_tests.conf`
- Copy `opcode-index.json` from repo root to `docs/`
- Keep existing awk HTML generation for backward compatibility

### 1c. Graphics test_info.json files

Create `test_info.json` for each of the 14 graphics tests with:
- name, description, swf_version
- empty opcodes (graphics tests don't test ActionScript opcodes)
- execution type: deterministic

### 1d. Rebuild and redeploy all examples

Run `build_all_examples.sh` to populate new data files.

---

## Phase 2: Dynamic Demo Page (demo.html)

### URL scheme
- `demo.html?test=trace_swf_4` — trace test
- `demo.html?test=graphics/three_boxes` — graphics test
- `demo.html?test=trace_swf_4&compare=true` — with Ruffle comparison

### Emscripten dynamic loading
1. Define `window.Module` with `locateFile` before loading Emscripten script
2. `Module.locateFile(path)` returns correct directory prefix
3. Dynamically inject `<script>` tag for test's JS file

### Page layout
- Header with test name and back link
- Metadata section from test_info.json
- Canvas (graphics only) + trace output console
- Run/Clear buttons
- Comparison panel (hidden by default)

### Demo type detection
- URL prefix `graphics/` → graphics mode
- Fallback: test_info.json type field
- Graphics: show canvas, async ccall
- Trace: hide canvas, sync ccall

---

## Phase 3: Ruffle Side-by-Side Comparison

- Load Ruffle from CDN on demand (only when activated)
- Toggle button switches single/two-column layout
- URL updates via `history.replaceState` for shareable state
- All files same-origin, no CORS issues

---

## Phase 4: Index Page Redesign

### Sections
1. Header with SWFRecomp title
2. Stats bar (opcode count, demo count)
3. Search/filter (text, type, opcode)
4. Opcode summary table from opcode-index.json (deduplicated by hex, prefer type=spec)
5. Demo cards grid from catalog.json
6. Excluded tests from catalog.json
7. How It Works / Links

### Template approach
Static HTML template with JS data loading, copied from scripts/templates/ during generation.

---

## Phase 5: Redirect Stubs & Build Integration

### Per-test redirect pages
Replace full HTML templates with minimal meta-refresh redirects to `demo.html?test=<name>`.

### Build script changes
- `build_test.sh`: Generate redirect stub instead of full template copy
- `deploy_example.sh`: Already updated in Phase 1
- `build_all_examples.sh`: No structural changes needed

---

## Phase 6: Graphics SWF Generation (Future/Independent)

- Create shared `swf_builder.py` library
- Create `create_test_swf.py` for each graphics test
- Start with simple tests, build up to complex ones
- Independent of Phases 1-5

---

## Implementation Order

| Phase | Enables | Dependencies |
|-------|---------|--------------|
| 1 | Data files deployed; catalog.json exists | None |
| 2 | Dynamic demo page works | Phase 1 |
| 3 | Ruffle comparison | Phase 2 |
| 4 | Index shows opcode data + demo links | Phase 1 |
| 5 | Old URLs redirect; pipeline integrated | Phase 2 |
| 6 | Graphics SWF generation | None |

Starting point: Phase 1 + Phase 2 together.
