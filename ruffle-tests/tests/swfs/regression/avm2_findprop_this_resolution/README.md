# avm2_findprop_this_resolution

Regression net for the recompiler's find→this lever (unqualified own-member
access resolved at compile time to a direct `this` receiver + baked slot
read). Covers plain slot reads, subclass shadowing, getters, unqualified
own-method calls, unqualified statics (must NOT bind to `this`), a name
colliding with a package-level function (must fall through to the domain),
dynamic classes, `with`-blocks and try/catch bodies (both must gate the
substitution off).

Note: mxmlc compiles unqualified instance-member reads as
`getlocal0+getproperty`, so the find→this substitution itself is exercised
mainly by upstream avm2 tests compiled with the older ASC
(es4_protected_inheritance, class_supercalls_errors) and by the RWK/Flixel
games; this test pins the RESOLUTION SEMANTICS the lever must preserve.

Line 8 (`sub.readShadowed: base-shadowed`) is the private-namespace
identity row, and it was FIXED in the polish sweep's session 5 (`b4d4457f1`).
It used to read `sub-shadowed`: mxmlc emits private namespaces with EMPTY
uris (unique only by pool index), our runtime compared namespaces by
(kind, uri), so Base's and Sub's private namespaces conflated and Sub's
shadowing slot overrode Base's ivtable entry. Real Flash keeps private
namespaces distinct per class (lexical private scoping), and `Base`'s
`readShadowed()` reads BASE's `private var shadowed` even on a `Sub`
receiver — private members are not virtual. `Avm2PropKey::ns_priv` (runtime)
and `NsKey::priv` + the `findUniqueSlot` site check (recompiler) now
compare private namespaces by pool-entry identity, so this row prints what
Flash prints. This test was the only place in the corpus that pinned the
old behavior, which is why it is the one row this file predicted would
flip.
