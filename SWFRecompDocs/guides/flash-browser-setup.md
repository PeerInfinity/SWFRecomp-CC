# Setting Up a Flash-Capable Browser (Basilisk + Clean Flash)

Modern browsers no longer support Flash Player. To run SWF content in a browser
(e.g. for the Seedling Archipelago client), you need a
legacy browser with NPAPI plugin support and a patched Flash Player plugin.

## Overview

- **Browser:** Basilisk (32-bit) — an independent browser based on the Goanna
  engine that still supports NPAPI plugins.
- **Flash Plugin:** Clean Flash (NPAPI, 32-bit) — a patched version of the
  Chinese Flash Player distribution with adware/spyware removed.

## Why These Specific Choices

- **32-bit Basilisk** is required because the Flash NPAPI plugin is only
  available as a 32-bit DLL. A 64-bit browser cannot load 32-bit plugins.
- **Clean Flash** exists because Adobe killed Flash worldwide in December 2020,
  but a Chinese company (Zhongcheng Network, licensed by Adobe) continued
  distributing and updating Flash Player for the Chinese market. Those builds
  include bundled adware/spyware. The
  [clean-flash-builds](https://github.com/darktohka/clean-flash-builds) project
  patches out the unwanted components, producing safe builds with version
  numbers in the 34.x range.

## Step 1: Install Basilisk (32-bit)

1. Download the **32-bit** installer from [basilisk-browser.org/download.html](https://basilisk-browser.org/download.html).
2. Windows SmartScreen may flag it as untrusted (the binary isn't code-signed).
   If your antivirus doesn't flag it, proceed with "Run anyway."
3. Run a **Standard** install. Default location: `C:\Program Files (x86)\Basilisk\`.

## Step 2: Download Clean Flash

1. Go to [clean-flash-builds releases](https://github.com/darktohka/clean-flash-builds/releases).
2. Download the latest **Windows** release (e.g. `ChineseFlash-Patched-Win-34.0.0.376.7z`).
   It's a single `.7z` archive (~30 MB) containing all plugin variants.
3. Extract with [7-Zip](https://www.7-zip.org/).

Inside the extracted folder you'll find:

```
flash32/          <-- 32-bit plugins (what we need)
flash64/          <-- 64-bit plugins
debug-flash32/    <-- 32-bit debug builds
debug-flash64/    <-- 64-bit debug builds
standalone-projector/
controlpanel/
FlashPatch.exe
README.txt
```

The two files you need from `flash32/`:
- `NPSWF32_34_0_0_376.dll` — the NPAPI plugin
- `flashplayer.xpt` — the plugin type library

## Step 3: Install the Plugin into Basilisk

The plugin must go in Basilisk's **profile** `plugins/` folder, not the install
directory.

1. Open Basilisk and navigate to `about:support`.
2. Find the **Profile Folder** row and click **Open Folder**.
   - Typical path: `C:\Users\<USER>\AppData\Roaming\Basilisk-Dev\Basilisk\Profiles\<id>.default\`
3. Create a `plugins` subfolder inside the profile folder if it doesn't exist.
4. Copy `NPSWF32_34_0_0_376.dll` and `flashplayer.xpt` into that `plugins/` folder.
5. Restart Basilisk.

**Note:** Putting the files in `C:\Program Files (x86)\Basilisk\plugins\` does
NOT work — Basilisk doesn't scan that directory for NPAPI plugins.

## Step 4: Verify

1. Navigate to `about:plugins` in Basilisk.
2. You should see **Shockwave Flash** listed with the NPSWF DLL path.
   - If it doesn't appear, check `about:config` and ensure `plugin.state.flash`
     is set to `2` (always activate).
3. Navigate to your Flash content (e.g. the Seedling Archipelago client) and confirm
   the "Flash Player Not Enabled!" message is gone.

## Alternative: Basilisk Portable with Flash (Pre-Bundled)

The Seedling Archipelago setup guide recommends a pre-packaged
[Basilisk Portable with Flash Player](https://archive.org/details/basilisk-portable-with-flash)
bundle from archive.org. However, as of April 2026, that item has been taken
down and is no longer available. Use the manual setup described above instead.

## Troubleshooting

- **Flash not detected in `about:plugins`:** Make sure the DLL is in the
  profile's `plugins/` folder, not the Basilisk install directory.
- **"Flash Player Not Enabled!" still showing:** Check `about:config` for
  `plugin.state.flash` — set it to `2`.
- **Wrong architecture:** You must use 32-bit Basilisk with 32-bit Flash. The
  NPAPI plugin is not available in 64-bit.
- **Windows SmartScreen warning:** Expected for Basilisk — it's a small project
  without code signing. Verify with your antivirus before proceeding.
