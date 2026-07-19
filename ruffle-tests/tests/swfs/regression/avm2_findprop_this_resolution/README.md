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

Caveat, line 8 (`sub.readShadowed: sub-shadowed`): mxmlc emits private
namespaces with EMPTY uris (unique only by pool index); our runtime compares
namespaces by (kind, uri), so Base's and Sub's private namespaces conflate
and Sub's shadowing slot overrides Base's ivtable entry. Real Flash keeps
private namespaces distinct per class (lexical private scoping) and would
print `base-shadowed`. Pre-existing runtime behavior, unrelated to the
find→this lever (identical output with SWF_NO_FIND_THIS=1 SWF_NO_SLOT_SPEC=1);
if private-ns identity is ever fixed, update this line.
