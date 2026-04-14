# Setting Up Flash Player in a Browser

Modern browsers no longer support Flash Player natively. There are two
approaches to run SWF content in a browser:

1. **Clean Flash Browser Extension** (recommended) — runs real Flash Player in
   modern Chrome or Firefox via a native messaging host.
2. **Legacy browser (Basilisk/Waterfox Classic)** — uses the NPAPI plugin
   directly, but lacks modern JavaScript features.

Both approaches use **Clean Flash**, a patched version of the Chinese Flash
Player distribution with adware/spyware removed. Adobe killed Flash worldwide
in December 2020, but a Chinese company (Zhongcheng Network, licensed by Adobe)
continued distributing and updating Flash Player for the Chinese market. Those
builds include bundled adware/spyware. The
[clean-flash-builds](https://github.com/darktohka/clean-flash-builds) project
patches out the unwanted components, producing safe builds with version numbers
in the 34.x range.

---

## Option 1: Clean Flash Browser Extension (Chrome/Firefox)

This is the recommended approach. It uses real Flash Player in modern Chrome or
Firefox via a Manifest V3 extension and a sandboxed native host process written
in Rust.

**GitHub:** [darktohka/clean-flash-browser-extension](https://github.com/darktohka/clean-flash-browser-extension)

### Prerequisites

- **Rust toolchain** — install from [rustup.rs](https://rustup.rs/). The
  default MSVC toolchain is fine.
- **Visual Studio C++ build tools** — the Rust installer will tell you if
  they're missing.
- **Python 3** — for the install script (needs native Windows Python, not WSL).
- **7-Zip** — to extract the Clean Flash archive.

### Step 1: Download Clean Flash (PPAPI plugin)

1. Go to [clean-flash-builds releases](https://github.com/darktohka/clean-flash-builds/releases).
2. Download the latest **Windows** release (e.g. `ChineseFlash-Patched-Win-34.0.0.376.7z`).
   It's a single `.7z` archive (~30 MB) containing all plugin variants.
3. Extract with 7-Zip.
4. Copy the 64-bit PPAPI plugin to a permanent location:
   ```
   copy flash64\pepflashplayer64_34_0_0_376.dll
        "%LOCALAPPDATA%\Flash Player\"
   ```

### Step 2: Set FLASH_PLUGIN_PATH

The native host needs to know where the PPAPI Flash DLL is. Set a persistent
user environment variable from PowerShell:

```powershell
[Environment]::SetEnvironmentVariable(
    "FLASH_PLUGIN_PATH",
    "C:\Users\<USER>\AppData\Local\Flash Player\pepflashplayer64_34_0_0_376.dll",
    "User"
)
```

Restart Chrome/Firefox after setting this so they pick it up.

### Step 3: Build the native messaging host

```bash
git clone https://github.com/darktohka/clean-flash-browser-extension.git
cd clean-flash-browser-extension
cargo build --release -p player-web
```

This compiles `target/release/flash-player-host.exe`. The first build takes
several minutes as it compiles all Rust dependencies.

### Step 4: Apply patches (save data fix)

The extension has two issues that need patching:

1. **SharedObject persistence** — Flash generates a random directory name for
   save data on each launch, so saves are lost between sessions.
2. **Firefox manifest compatibility** — Firefox doesn't support
   `background.service_worker` in Manifest V3.

Apply the patch file from `SWFRecompDocs/guides/clean-flash-extension-patches.diff`:

```bash
cd clean-flash-browser-extension
git apply /path/to/clean-flash-extension-patches.diff
cargo build --release -p player-web
```

**What the SharedObject patch does:** Flash stores save data (Local Shared
Objects / `.sol` files) under `#SharedObjects/<ID>/` where `<ID>` is normally a
random 8-character string generated each time the PPAPI host starts. In real
Chrome, Flash gets a stable profile path from the browser; this extension
doesn't provide one, so each session creates a new random directory and can't
find previous saves. The patch intercepts Flash's file I/O in
`PPB_Flash_File_ModuleLocal` and rewrites the random `<ID>` to a deterministic
hash of the page URL origin, so save data persists across sessions.

Save data is stored at:
`%APPDATA%\flash-player\PepperFlash\WritableRoot\#SharedObjects\<stable_id>\`

### Step 5: Register the native messaging host

Run the install script with native Windows Python (not WSL):

```bash
cd web-extension
python install-host.py
```

This writes manifest JSON files to `%LOCALAPPDATA%\Flash Player\NativeMessagingHosts\`
and registers them in the Windows registry for Chrome, Chromium, Brave, and
Firefox.

### Step 6a: Load the extension in Chrome

1. Go to `chrome://extensions`
2. Enable **Developer Mode** (toggle in top right)
3. Click **Load unpacked**
4. Select the `web-extension/` directory from the cloned repo

### Step 6b: Load the extension in Firefox

1. Go to `about:debugging#/runtime/this-firefox`
2. Click **Load Temporary Add-on**
3. Select `web-extension/manifest.json`

**Note:** "Load Temporary Add-on" means the extension only persists until you
close Firefox. For permanent installation, either sign the extension through
Mozilla or set `xpinstall.signatures.required` to `false` in `about:config`.

### Step 7: Configure the extension

1. Pin the Flash Player extension to Chrome's toolbar (click the puzzle piece
   icon, then pin).
2. Click the extension icon to open settings.
3. Go to the **Sandboxing** tab.
4. Under **File System Access**, uncheck **"Allow access to whitelisted files
   and folders only"**. This is required for Flash save data (SharedObjects) to
   work. Without this, Flash cannot write `.sol` files to disk.
5. Reload the page.

### Performance notes

- Chrome runs Flash content significantly faster than Ruffle, with only minor
  occasional jerkiness from the native messaging overhead.
- Firefox works but may experience slowdowns after initial load. Chrome is the
  better choice for now.

### Known limitations

- **Multiple tabs with the same Flash game cause save corruption.** Each tab
  spawns its own `flash-player-host.exe` process. If two tabs run the same
  game, both processes read/write the same `.sol` file, causing file contention
  and lost saves. Only run one tab per Flash game at a time.

- **Firefox performance.** Firefox may slow down significantly after initial
  Flash content load. Chrome is recommended.

- **Tracing kills performance.** If you set the `TRACE_FLASH` environment
  variable for debugging, remove it when done — it logs every Flash API call
  and causes severe slowdowns. Remove with:
  ```powershell
  [Environment]::SetEnvironmentVariable("TRACE_FLASH", $null, "User")
  [Environment]::SetEnvironmentVariable("FLASH_PLAYER_LOG_DIR", $null, "User")
  ```

- **Rebuilding requires closing browsers.** The `flash-player-host.exe` binary
  is locked while Chrome/Firefox are running. Close all browsers before
  rebuilding.

---

## Option 2: Legacy Browser (Basilisk or Waterfox Classic)

Use this if you can't build the extension from source, or if the page you're
loading doesn't need modern JavaScript features.

### Limitations

- **Basilisk** does not support worker threads.
- **Waterfox Classic** does not support modern JavaScript (e.g. optional
  chaining, nullish coalescing).
- Both are unmaintained or minimally maintained legacy browsers.
- Save data works reliably in legacy browsers (no flush timing issues).

### Browser choices

- **Basilisk (32-bit):** Download from [basilisk-browser.org/download.html](https://basilisk-browser.org/download.html).
  Must use the 32-bit version since the NPAPI plugin is 32-bit only. Windows
  SmartScreen may flag it as untrusted (not code-signed). Standard install is
  fine.

- **Waterfox Classic (64-bit):** Download from
  [GitHub releases](https://github.com/BrowserWorks/Waterfox-Classic/releases).
  The final release is 2022.11 (repo archived December 2025). Uses the 64-bit
  NPAPI plugin.

### Download Clean Flash (NPAPI plugin)

Same archive as Option 1. The files you need depend on the browser:

- **Basilisk (32-bit):** `flash32/NPSWF32_34_0_0_376.dll` and `flash32/flashplayer.xpt`
- **Waterfox Classic (64-bit):** `flash64/NPSWF64_34_0_0_376.dll` and `flash64/flashplayer.xpt`

### Install the plugin

The plugin must go in the browser's **profile** `plugins/` folder, not the
install directory.

1. Open the browser and navigate to `about:support`.
2. Find the **Profile Folder** row and click **Open Folder**.
   - Basilisk: `C:\Users\<USER>\AppData\Roaming\Basilisk-Dev\Basilisk\Profiles\<id>.default\`
   - Waterfox: `C:\Users\<USER>\AppData\Roaming\Waterfox\Profiles\<id>.default\`
3. Create a `plugins` subfolder inside the profile folder if it doesn't exist.
4. Copy the DLL and `.xpt` file into that `plugins/` folder.
5. Restart the browser.

**Important:** Putting the files in the browser's install directory (e.g.
`C:\Program Files (x86)\Basilisk\plugins\`) does NOT work.

### Verify

1. Navigate to `about:plugins`.
2. You should see **Shockwave Flash** listed.
   - If not, check `about:config` and ensure `plugin.state.flash` is set to
     `2` (always activate).
3. If Flash shows up but content still says "Flash Player Not Enabled!", the
   plugin may be in "Ask to Activate" mode — click the gray box or set
   `plugin.state.flash` to `2`.
4. Navigate to your Flash content and confirm it loads.

### Pre-bundled alternative (no longer available)

The Seedling Archipelago setup guide recommends a pre-packaged
[Basilisk Portable with Flash Player](https://archive.org/details/basilisk-portable-with-flash)
bundle from archive.org. As of April 2026, that item has been taken down and is
no longer available.

---

## Troubleshooting

- **Flash not detected in `about:plugins` (legacy browser):** Make sure the DLL
  is in the profile's `plugins/` folder, not the browser install directory.
- **"Flash Player Not Enabled!" still showing:** Check `about:config` for
  `plugin.state.flash` — set it to `2`.
- **Gray box instead of Flash content:** Flash is in click-to-play mode. Click
  the box or set `plugin.state.flash` to `2` in `about:config`.
- **Wrong architecture (legacy browser):** Basilisk needs 32-bit Flash;
  Waterfox Classic needs 64-bit Flash.
- **Extension not working:** Make sure `FLASH_PLUGIN_PATH` is set and you
  restarted the browser after setting it.
- **Firefox extension error about `service_worker`:** Apply the patch described
  in Step 4 above.
- **Firefox extension disappears on restart:** Temporary add-ons don't persist.
  Set `xpinstall.signatures.required` to `false` in `about:config` and install
  the extension as a regular `.xpi` file, or re-load it each session.
- **Save data not persisting (extension):** Check that the file whitelist is
  disabled in the extension settings (Sandboxing tab). Also ensure the
  SharedObject patch from Step 4 is applied.
- **Save data lost on refresh (extension):** Known limitation — see "Known
  limitations" above. Wait a moment before refreshing, or use a legacy browser
  for games where save reliability is critical.
- **Severe performance degradation:** Check if `TRACE_FLASH` environment
  variable is set — remove it if so.
- **Build fails with "Access is denied":** Close all browsers before rebuilding,
  as the host exe is locked while in use.
- **Windows SmartScreen warning:** Expected for Basilisk — it's a small project
  without code signing. Verify with your antivirus before proceeding.
