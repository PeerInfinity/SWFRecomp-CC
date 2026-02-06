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
    echo "Error: Index file not found: $INDEX_FILE"
    exit 1
fi

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
