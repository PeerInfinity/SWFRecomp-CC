# avm2_parent_child_symbolclass_domain

A character placed by a **loaded AS3 child** must get its `SymbolClass` class
resolved in the ApplicationDomain of the movie **instance** that placed it, not
in the root domain. Ruffle: `movie_clip.rs` `preload_symbol_class` looks every
row up in `library_for_movie(self.movie()).avm2_domain()`, and every load builds
a fresh `SwfMovie`, so the key is (movie instance, character id).

Closeout: `SWFRecompDocs/status/avm2-child-symbolclass-binding.md`. The corpus
test that motivated it is `avm2/loader_duplicate_class`.

## The shape

    test.swf   AVM2 (mxmlc, Test.as)   Loader.load("child.swf"), default LoaderContext
    child.swf  AVM2 (mxmlc, Child.as + Inner.as + Outer.as), then tag-injected:
               DefineSprite 1 (Inner, empty), DefineSprite 2 (Outer, places 1),
               SymbolClass 1 -> Inner, 2 -> Outer, root frame 1 places 2

The default LoaderContext loads the child into a **fresh** child domain, so
`Inner` and `Outer` exist there and nowhere else (the `parent:Inner visible=false`
rows confirm it before and after the load).

| row | path it grades | pre-fix |
|---|---|---|
| `timeline:Outer kid:Inner` + the `Inner ctor` / `Outer ctor` lines above `Child ctor` | the child ROOT's frame 1 places char 2; char 2's frame places char 1. Both resolve through `class_for_char` with the placing parent's `movie_scope` | `timeline:flash.display::MovieClip kid:flash.display::MovieClip`, no ctor lines |
| `script:Outer kid:Inner` + the `Inner ctor` / `Outer ctor, kid=Inner` lines under `script: new Outer()` | a SCRIPT-created symbol instance (`new Outer()` via the child domain's `getDefinition`). Its class is right by construction; what it has to get right is the child it places, which inherits the scope the allocator stamps from the class's own ABC file (`child_class_movie_scope`) | `kid=flash.display::MovieClip`, no `Inner ctor` |

The script row exists because `avm2/loader_duplicate_class` does not grade that
arm: its script-created `DuplicateClass` instances place only unbound children.

## Oracle

`output.txt` is the local Ruffle exporter's trace, byte for byte
(`RUFFLE_LOCAL_FETCH_DIR` serving `child.swf`; the exporter's default movie URL is
`http://armorgames.com/`, so the file goes under `<dir>/armorgames.com/`).

## Rebuild

    python3 create_test_swf.py     # needs ~/CC/flex-sdk/bin/mxmlc
