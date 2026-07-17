// Source for regression/sort_comparator_captured_scope (test.swf).
//
// NORMALIZATION (pass (b) remainder / master-list item 7 — sort comparator
// captured scopes for type-2). _invoke_sort_comparator's type-2 arm passed
// flags=0 (no captured scopes), so a factory-returned DefineFunction2 closure
// comparator lost its captured outer local: it resolved to undefined, the
// comparator returned NaN, and the array never reordered. Flash restores a
// closure's captured scope chain for every call, including a sort comparator.
// Fix: INV_CAPTURED_SCOPE on the type-2 branch.
//
// makeCmp's activation is GONE by the time sort() calls cmp, so `factor` is
// reachable ONLY through the closure's captured scopes (not the live chain).
//
// Build (SWF8, DefineFunction2 — MTASC; hand-assembly of a closure-capturing
// func2 is impractical):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main \
//     -header 200:150:30 SortCapturedScope.as -swf test.swf -version 8
//
// Deterministic: a 2-element array [20,10] does exactly one comparison.
// Fail-before: factor=undefined, sorted=20,10 (no reorder).
// Pass-after:  factor=100,       sorted=10,20.
class SortCapturedScope {
    static function makeCmp() {
        var factor = 100;   // captured; makeCmp's frame is gone when cmp runs
        return function(a, b) {
            trace("cmp a=" + a + " b=" + b + " factor=" + factor);
            return (a - b) * factor;
        };
    }
    static function main() {
        var cmp = makeCmp();
        var arr = [20, 10];
        arr.sort(cmp);
        trace("sorted=" + arr.join(","));
    }
}
