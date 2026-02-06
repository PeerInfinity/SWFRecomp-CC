#!/bin/bash
# Generate the examples section for docs/index.html
# Usage: ./scripts/generate_examples_index.sh [docs_dir]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
DOCS_DIR=${1:-"${SWFRECOMP_ROOT}/../docs"}
EXAMPLES_DIR="${DOCS_DIR}/examples"
INDEX_FILE="${DOCS_DIR}/index.html"

# Load exclude list from shared config file
EXCLUDE_CONFIG="${SCRIPT_DIR}/excluded_tests.conf"
EXCLUDE_TESTS=()

if [ -f "$EXCLUDE_CONFIG" ]; then
    # Read exclude list (skip comments and empty lines, keep full line with reason)
    while IFS= read -r line || [ -n "$line" ]; do
        # Skip comments and empty lines
        [[ "$line" =~ ^#.*$ ]] && continue
        [[ -z "$line" ]] && continue
        EXCLUDE_TESTS+=("$line")
    done < "$EXCLUDE_CONFIG"
fi

if [ ! -d "$EXAMPLES_DIR" ]; then
    echo "Error: Examples directory not found: $EXAMPLES_DIR"
    exit 1
fi

# Discover trace examples (top-level directories with .demo_type = "trace" or no .demo_type)
TRACE_EXAMPLES=()
GRAPHICS_EXAMPLES=()

for example_dir in "${EXAMPLES_DIR}"/*/; do
    [ -d "$example_dir" ] || continue
    example_name=$(basename "$example_dir")

    # Check if this is the graphics/ subdirectory
    if [ "$example_name" = "graphics" ]; then
        # Scan graphics subdirectories
        for gfx_dir in "${example_dir}"/*/; do
            [ -d "$gfx_dir" ] || continue
            gfx_name=$(basename "$gfx_dir")
            GRAPHICS_EXAMPLES+=("$gfx_name")
        done
    else
        # Read demo type from marker file
        demo_type="trace"
        if [ -f "${example_dir}/.demo_type" ]; then
            demo_type=$(cat "${example_dir}/.demo_type" | tr -d '[:space:]')
        fi

        if [ "$demo_type" = "graphics" ]; then
            GRAPHICS_EXAMPLES+=("$example_name")
        else
            TRACE_EXAMPLES+=("$example_name")
        fi
    fi
done

# Sort arrays
if [ ${#TRACE_EXAMPLES[@]} -gt 0 ]; then
    IFS=$'\n' TRACE_EXAMPLES=($(sort <<<"${TRACE_EXAMPLES[*]}"))
    unset IFS
fi
if [ ${#GRAPHICS_EXAMPLES[@]} -gt 0 ]; then
    IFS=$'\n' GRAPHICS_EXAMPLES=($(sort <<<"${GRAPHICS_EXAMPLES[*]}"))
    unset IFS
fi

TOTAL_EXAMPLES=$(( ${#TRACE_EXAMPLES[@]} + ${#GRAPHICS_EXAMPLES[@]} ))

if [ $TOTAL_EXAMPLES -eq 0 ]; then
    echo "No examples found in $EXAMPLES_DIR"
    exit 0
fi

echo "Found ${#TRACE_EXAMPLES[@]} trace examples and ${#GRAPHICS_EXAMPLES[@]} graphics examples"

HAS_GRAPHICS=false
if [ ${#GRAPHICS_EXAMPLES[@]} -gt 0 ]; then
    HAS_GRAPHICS=true
fi

# Generate trace demo cards HTML
DEMO_CARDS=""
for example in "${TRACE_EXAMPLES[@]}"; do
    # Determine description based on test name
    DESCRIPTION="Flash SWF test demonstrating "
    case "$example" in
        trace*)
            DESCRIPTION+="console output with the <code>trace()</code> function."
            ;;
        add_floats*)
            DESCRIPTION+="floating-point arithmetic addition operations."
            ;;
        add_strings*)
            DESCRIPTION+="string concatenation with the <code>add</code> operator."
            ;;
        *float*)
            DESCRIPTION+="floating-point arithmetic operations."
            ;;
        *string*)
            DESCRIPTION+="string manipulation and operations."
            ;;
        *var*)
            DESCRIPTION+="variable storage and retrieval with ActionScript."
            ;;
        *)
            DESCRIPTION+="ActionScript bytecode recompilation to WebAssembly."
            ;;
    esac

    DEMO_CARDS+="
                <div class=\"demo-card\">
                    <h3>$example</h3>
                    <p>$DESCRIPTION</p>
                    <a href=\"examples/$example/\" class=\"demo-link\">View Demo →</a>
                </div>
"
done

# Generate graphics demo cards HTML
GRAPHICS_CARDS=""
for example in "${GRAPHICS_EXAMPLES[@]}"; do
    DESCRIPTION="WebGPU-rendered Flash graphics demo"
    case "$example" in
        *gradient*)
            DESCRIPTION+=" showing gradient fills and color interpolation."
            ;;
        *box*|*square*)
            DESCRIPTION+=" rendering geometric shapes with solid fills."
            ;;
        *circle*|*coicle*)
            DESCRIPTION+=" rendering curved shapes and ellipses."
            ;;
        *text*)
            DESCRIPTION+=" with text rendering and glyph layout."
            ;;
        *shadow*)
            DESCRIPTION+=" with shadow and filter effects."
            ;;
        *style*|*shape*)
            DESCRIPTION+=" with mixed line styles and fill types."
            ;;
        *)
            DESCRIPTION+=" with shape rendering and color transforms."
            ;;
    esac

    GRAPHICS_CARDS+="
                <div class=\"demo-card\" style=\"border-left: 3px solid #7B1FA2;\">
                    <h3>$example <span style=\"display:inline-block;background:#7B1FA2;color:white;padding:2px 8px;border-radius:10px;font-size:0.7em;vertical-align:middle;margin-left:8px;\">WebGPU</span></h3>
                    <p>$DESCRIPTION</p>
                    <a href=\"examples/graphics/$example/\" class=\"demo-link\" style=\"color:#7B1FA2;\">View Demo →</a>
                </div>
"
done

# Generate excluded tests section
EXCLUDED_SECTION=""
if [ ${#EXCLUDE_TESTS[@]} -gt 0 ]; then
    EXCLUDED_SECTION="
            <section>
                <h2>Excluded Tests</h2>
                <p>The following tests are currently excluded from the live demos due to known issues:</p>

                <div style=\"margin: 20px 0;\">
"

    for exclude_entry in "${EXCLUDE_TESTS[@]}"; do
        # Split on first colon to get test name and reason
        test_name="${exclude_entry%%:*}"
        reason="${exclude_entry#*:}"

        EXCLUDED_SECTION+="
                    <div style=\"background: #1f1f1f; padding: 15px; border-radius: 8px; margin: 10px 0; border-left: 4px solid #ff9800;\">
                        <h3 style=\"color: #ff9800; margin: 0 0 8px 0; font-size: 1.1em;\">$test_name</h3>
                        <p style=\"color: #b0b0b0; margin: 0; font-size: 0.95em;\">$reason</p>
                    </div>
"
    done

    EXCLUDED_SECTION+="
                </div>
            </section>
"
fi

# Read the current index.html
if [ ! -f "$INDEX_FILE" ]; then
    echo "Warning: Index file not found: $INDEX_FILE — skipping HTML update"
    # Skip to catalog.json generation below
    SKIP_AWK=true
else
    SKIP_AWK=false
fi

# Check if index.html uses the new JS-driven format (no awk injection needed)
if [ "$SKIP_AWK" = false ] && ! grep -q 'class="demo-section"' "$INDEX_FILE" 2>/dev/null; then
    echo "Index uses JS-driven format — skipping awk HTML injection"
    SKIP_AWK=true
fi

if [ "$SKIP_AWK" = false ]; then

# Build the trace demos heading
TRACE_HEADING="
                <h2 style=\"margin-top: 40px;\">Trace Demos</h2>
                <p style=\"margin-bottom: 20px; color: #b0b0b0;\">These demos run recompiled ActionScript and display trace output in the browser.</p>"

# Create a temporary file with updated content
TEMP_FILE=$(mktemp)

# Use awk to replace the demo-section content and add excluded section
# Graphics demos are listed first, then trace demos
awk -v graphics_cards="$GRAPHICS_CARDS" -v trace_heading="$TRACE_HEADING" -v trace_cards="$DEMO_CARDS" -v has_graphics="$HAS_GRAPHICS" -v excluded="$EXCLUDED_SECTION" '
    BEGIN { in_demo_section = 0; in_excluded_section = 0; skip_next_section = 0 }

    # Start of demo section
    /<section class="demo-section">/ {
        in_demo_section = 1
        print
        if (has_graphics == "true") {
            print "                <h2 style=\"color: #7B1FA2; border-bottom: 2px solid #7B1FA2;\">Graphics Demos (WebGPU)</h2>"
            print "                <p style=\"margin-bottom: 20px; color: #b0b0b0;\">These demos render Flash vector graphics via WebGPU. Requires a WebGPU-capable browser.</p>"
            print ""
            print graphics_cards
        }
        print trace_heading
        print ""
        print trace_cards
        next
    }

    # End of demo section
    in_demo_section && /<\/section>/ {
        in_demo_section = 0
        skip_next_section = 1
        print
        # Insert excluded section after demo section
        if (excluded != "") {
            print excluded
        }
        next
    }

    # Check if next section is old excluded section - if so, skip it
    /<section>/ && skip_next_section {
        skip_next_section = 0
        # Peek at next line
        getline next_line
        if (next_line ~ /<h2>Excluded Tests<\/h2>/) {
            in_excluded_section = 1
            next
        } else {
            # Not excluded section, print normally
            print
            print next_line
            next
        }
    }

    # Skip everything inside old excluded section
    in_excluded_section {
        if (/<\/section>/) {
            in_excluded_section = 0
        }
        next
    }

    # Skip lines inside sections we are replacing
    in_demo_section { next }

    # Print all other lines
    { print }
' "$INDEX_FILE" > "$TEMP_FILE"

# Replace the original file
mv "$TEMP_FILE" "$INDEX_FILE"

echo "✅ Updated $INDEX_FILE with ${#TRACE_EXAMPLES[@]} trace demos and ${#GRAPHICS_EXAMPLES[@]} graphics demos"
echo ""
echo "Trace demos:"
for example in "${TRACE_EXAMPLES[@]}"; do
    echo "  - $example"
done
if [ ${#GRAPHICS_EXAMPLES[@]} -gt 0 ]; then
    echo "Graphics demos:"
    for example in "${GRAPHICS_EXAMPLES[@]}"; do
        echo "  - $example"
    done
fi

fi  # end SKIP_AWK check

# --- Generate catalog.json ---
echo ""
echo "Generating catalog.json..."

CATALOG_FILE="${DOCS_DIR}/catalog.json"
REPO_ROOT="${SWFRECOMP_ROOT}/.."

# Build lists of test entries for the Python script
TRACE_LIST=""
for example in "${TRACE_EXAMPLES[@]}"; do
    TRACE_LIST+="${example},"
done

GRAPHICS_LIST=""
for example in "${GRAPHICS_EXAMPLES[@]}"; do
    GRAPHICS_LIST+="${example},"
done

EXCLUDE_LIST=""
for exclude_entry in "${EXCLUDE_TESTS[@]}"; do
    EXCLUDE_LIST+="${exclude_entry}|"
done

python3 - "$EXAMPLES_DIR" "$TRACE_LIST" "$GRAPHICS_LIST" "$EXCLUDE_LIST" "$CATALOG_FILE" <<'PYEOF'
import json, sys, os
from datetime import datetime, timezone

examples_dir = sys.argv[1]
trace_names = [t for t in sys.argv[2].rstrip(',').split(',') if t]
graphics_names = [g for g in sys.argv[3].rstrip(',').split(',') if g]
exclude_raw = [e for e in sys.argv[4].rstrip('|').split('|') if e]
catalog_file = sys.argv[5]

tests = []

for name in trace_names:
    test_dir = os.path.join(examples_dir, name)
    entry = {
        "id": name,
        "name": name,
        "type": "trace",
        "path": f"examples/{name}",
        "has_swf": os.path.exists(os.path.join(test_dir, "test.swf")),
    }

    # Find JS/WASM files
    for f in os.listdir(test_dir):
        if f.endswith('.js') and not f.startswith('.'):
            entry["js_file"] = f
        elif f.endswith('.wasm'):
            entry["wasm_file"] = f

    # Read test_info.json if present
    info_path = os.path.join(test_dir, "test_info.json")
    if os.path.exists(info_path):
        with open(info_path) as f:
            info = json.load(f)
        meta = info.get("metadata", {})
        entry["description"] = meta.get("description", "")
        entry["swf_version"] = meta.get("swf_version")
        entry["fully_implemented"] = meta.get("fully_implemented", False)
        opcodes = info.get("opcodes", {})
        entry["opcodes_tested"] = opcodes.get("tested", [])
        entry["opcodes_supporting"] = opcodes.get("supporting", [])

    tests.append(entry)

for name in graphics_names:
    test_dir = os.path.join(examples_dir, "graphics", name)
    entry = {
        "id": f"graphics/{name}",
        "name": name,
        "type": "graphics",
        "path": f"examples/graphics/{name}",
        "has_swf": os.path.exists(os.path.join(test_dir, "test.swf")),
    }

    for f in os.listdir(test_dir):
        if f.endswith('.js') and not f.startswith('.'):
            entry["js_file"] = f
        elif f.endswith('.wasm'):
            entry["wasm_file"] = f

    info_path = os.path.join(test_dir, "test_info.json")
    if os.path.exists(info_path):
        with open(info_path) as f:
            info = json.load(f)
        meta = info.get("metadata", {})
        entry["description"] = meta.get("description", "")
        entry["swf_version"] = meta.get("swf_version")
        entry["fully_implemented"] = meta.get("fully_implemented", False)
        opcodes = info.get("opcodes", {})
        entry["opcodes_tested"] = opcodes.get("tested", [])
        entry["opcodes_supporting"] = opcodes.get("supporting", [])

    tests.append(entry)

excluded = []
for raw in exclude_raw:
    parts = raw.split(':', 1)
    excluded.append({
        "name": parts[0].strip(),
        "reason": parts[1].strip() if len(parts) > 1 else ""
    })

catalog = {
    "generated": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
    "tests": tests,
    "excluded": excluded
}

with open(catalog_file, 'w') as f:
    json.dump(catalog, f, indent=2)

print(f"  Generated {catalog_file} with {len(tests)} tests and {len(excluded)} excluded")
PYEOF

# Copy opcode-index.json to docs/ if it exists in repo root
OPCODE_INDEX="${REPO_ROOT}/opcode-index.json"
if [ -f "$OPCODE_INDEX" ]; then
    cp "$OPCODE_INDEX" "${DOCS_DIR}/opcode-index.json"
    echo "  Copied opcode-index.json to ${DOCS_DIR}/"
fi

echo "✅ catalog.json generated"
