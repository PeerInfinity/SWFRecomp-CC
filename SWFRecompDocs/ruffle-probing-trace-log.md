# Ruffle exporter `--trace-log` probing patch

Local customization to the upstream Ruffle **exporter** (`~/CC/ruffle`) that
captures AVM `trace()` / warning output to a file while rendering a SWF. This is
how we generate Ruffle reference *trace* output (alongside the screenshot the
exporter normally produces) for the SWFRecomp test suites.

**Status:** verified still applied 2026-06-29 against Ruffle checkout HEAD
`7ea7c888` (2026-06-19, "avm2: Clean up TextLine"). The working-tree diff is
byte-identical to the saved patch (49 insertions, +3 deletions). Originally
re-applied 2026-05-29 (the checkout had been a shallow clone ~3 months stale;
updated to `origin/master`). The full patch is kept both at
`~/CC/ruffle/probing-trace-log.patch` and vendored in this repo at
`SWFRecompDocs/probing-trace-log.patch` for re-application after future updates.

> **Note:** the patch lives only in the working tree of the external
> `~/CC/ruffle` clone (uncommitted there). The built binary at
> `~/CC/ruffle/target/release/exporter` may lag the source — rebuild with
> `cargo +nightly build --release -p exporter` before generating fresh
> reference output if upstream has moved.

## What it adds

A `--trace-log <PATH>` CLI flag to `ruffle_exporter`. When set (single-SWF
export), every `avm_trace` message is written to `<PATH>`, one per line;
`avm_warning` messages are written prefixed with `Warning: `. Implemented via a
small `LogBackend` impl wired into the player through `PlayerBuilder::with_log`.

Usage:
```
ruffle_exporter <movie.swf> <out.png> --trace-log <out.txt>
```

## The three edits (≈49 lines)

- **`exporter/src/cli.rs`** — add the `Opt` field:
  ```rust
  /// Capture AVM trace() output to this file (one message per line).
  /// Only meaningful when exporting a single SWF.
  #[clap(long = "trace-log")]
  pub trace_log: Option<PathBuf>,
  ```

- **`exporter/src/exporter.rs`** — add a `TraceLogBackend` and wire it in:
  ```rust
  use ruffle_core::backend::log::LogBackend;

  #[derive(Clone, Default)]
  pub struct TraceLogBackend { output: Arc<Mutex<String>> }
  impl TraceLogBackend {
      pub fn take(&self) -> String { std::mem::take(&mut *self.output.lock().unwrap()) }
  }
  impl LogBackend for TraceLogBackend {
      fn avm_trace(&self, message: &str) {
          let mut o = self.output.lock().unwrap(); o.push_str(message); o.push('\n');
      }
      fn avm_warning(&self, message: &str) {
          let mut o = self.output.lock().unwrap();
          o.push_str("Warning: "); o.push_str(message); o.push('\n');
      }
  }
  ```
  Add a `trace_log: Option<TraceLogBackend>` field to `Exporter`, initialise it
  from `opt.trace_log` in `new()`, expose `trace_log(&self)`, and in
  `start_exporting_movie` switch the `PlayerBuilder` to a `mut builder` so it can
  conditionally `.with_log(log.clone())` before `.build()`.

- **`exporter/src/lib.rs`** — in `capture_single_swf`, after capturing frames:
  ```rust
  if let (Some(path), Some(log)) = (opt.trace_log.as_ref(), exporter.trace_log()) {
      std::fs::write(path, log.take())?;
  }
  ```

## Re-application notes

The `LogBackend` trait (`ruffle_core::backend::log`) and
`PlayerBuilder::with_log` are stable upstream APIs; the patch applied cleanly
onto the updated checkout. If a future update breaks it, re-derive from the three
edits above or `git apply` the patch (either `~/CC/ruffle/probing-trace-log.patch`
or the in-repo copy `SWFRecompDocs/probing-trace-log.patch`).
