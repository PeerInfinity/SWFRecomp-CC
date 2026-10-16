# Session 22 — wave-2 sibling file map (which slot edits what). Self-localize.

| slot | owner files / regions |
|---|---|
| w2-array-global | `action.c`: `actionInitArray` (~51528), `arguments` setup (~8446-8480), `String.split` result, `Array()`-as-function; `builtin_object_hasOwnProperty` (~4562) |
| w2-as-core | `action.c`: NEW static helper layer (as_get/as_set/as_call_method/as_new_global), AsBroadcaster (~36994-37094, ~39309), ContextMenu/Item (~2883-3040, ~41319-41370, ctor arms in `actionNewObject` ~59478-59560), AsSetupError (~5362); M5 flags in `actionCallMethod` object-method arm (~69639) + `objectToPrimitive` (~15524) |
