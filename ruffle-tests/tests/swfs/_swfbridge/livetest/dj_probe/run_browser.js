// run_browser.js — generic headed-Chrome console capture for the DJ probe.
// Loads a URL in real google-chrome (WebGPU via WSLg/DISPLAY for the WASM tier;
// Ruffle uses WebGL so it works too), captures ALL console + pageerror lines for
// CAPTURE_SECONDS, prints them to stdout, then exits. The probe's trace() lines
// (PROBE / PF<n> ...) are what we grep afterward.
//
// Env: HARNESS_URL, CHROME (default /usr/bin/google-chrome),
//      CAPTURE_SECONDS (default 12), CLICK_SELECTOR (optional: click after load),
//      CLICK_XY ("x,y" stage coords within CLICK_TARGET, default #ruffle-container),
//      CLICK_DELAY (ms before the XY click, default 3000),
//      KEYS ("t:code,..." inject keydown at t seconds, e.g. "5:39,7:37").
const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8089/ruffle_harness.html';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const SECONDS = parseInt(process.env.CAPTURE_SECONDS || '12', 10);
const CLICK = process.env.CLICK_SELECTOR || '';
const CLICK_XY = process.env.CLICK_XY || '';
const CLICK_TARGET = process.env.CLICK_TARGET || '#ruffle-container';
const CLICK_DELAY = parseInt(process.env.CLICK_DELAY || '3000', 10);

(async () => {
	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});
	try {
		const page = await browser.newPage();
		page.on('console', (m) => console.log(m.text()));
		page.on('pageerror', (e) => console.log('PAGEERROR: ' + e.message));
		await page.goto(URL, { waitUntil: 'load' });
		if (CLICK) {
			try {
				await page.waitForSelector(CLICK, { timeout: 8000 });
				await page.click(CLICK);
				console.log('[driver] clicked ' + CLICK);
			} catch (e) { console.log('[driver] click failed: ' + e.message); }
		}
		// Ruffle shows a modal "hardware acceleration is disabled" overlay when
		// Chrome's WebGL is software (no GPU in this headed instance). It covers
		// the canvas and intercepts clicks. Strip it (and the splash) from every
		// custom element's shadow DOM. Harmless on the WASM tier (no such overlay).
		const dismissRuffleOverlay = async () => {
			await page.evaluate(() => {
				document.querySelectorAll('*').forEach((el) => {
					if (el.shadowRoot) {
						el.shadowRoot.querySelectorAll(
							'#message-overlay, .modal, #splash-screen, .message-container'
						).forEach((m) => { m.style.display = 'none'; m.remove(); });
					}
				});
			});
		};

		const SHOT = process.env.SCREENSHOT_DIR || '';
		if (CLICK_XY) {
			const [sx, sy] = CLICK_XY.split(',').map(Number);
			await page.waitForTimeout(CLICK_DELAY);
			await dismissRuffleOverlay();
			if (SHOT) await page.screenshot({ path: SHOT + '/before_click.png' });
			const box = await page.locator(CLICK_TARGET).boundingBox();
			if (box) {
				console.log('[driver] target box: x=' + box.x.toFixed(0) + ' y=' + box.y.toFixed(0) + ' w=' + box.width.toFixed(0) + ' h=' + box.height.toFixed(0));
				const px = box.x + sx, py = box.y + sy;
				// move first (button rollover), then click.
				await dismissRuffleOverlay();
				await page.mouse.move(px, py);
				await page.waitForTimeout(200);
				await page.mouse.click(px, py);
				console.log('[driver] clicked stage (' + sx + ',' + sy + ') -> page (' + px.toFixed(0) + ',' + py.toFixed(0) + ')');
				await page.waitForTimeout(1500);
				if (SHOT) await page.screenshot({ path: SHOT + '/after_click.png' });
			} else {
				console.log('[driver] CLICK_TARGET ' + CLICK_TARGET + ' not found');
			}
		} else if (SHOT) {
			await page.waitForTimeout(CLICK_DELAY);
			await page.screenshot({ path: SHOT + '/menu.png' });
		}
		// Optional keyboard steer schedule (Q5 browser DOM-keydown path): focus the
		// canvas, then hold Right, then Left, while the keyspy probe logs Key.isDown
		// + hero._x. STEER_KEYS=1 enables.
		if (process.env.STEER_KEYS === '1') {
			await page.waitForTimeout(3000);
			await dismissRuffleOverlay();
			try { await page.locator('#canvas').click({ timeout: 1500 }); } catch (e) {
				// Ruffle tier: no #canvas; click the player container for key focus
				try { await page.locator(CLICK_TARGET).click({ timeout: 1500 }); } catch (e2) {}
			}
			await page.keyboard.down('ArrowRight');
			console.log('[driver] ArrowRight DOWN');
			await page.waitForTimeout(2500);
			await page.keyboard.up('ArrowRight');
			console.log('[driver] ArrowRight UP');
			await page.keyboard.down('ArrowLeft');
			console.log('[driver] ArrowLeft DOWN');
			await page.waitForTimeout(2500);
			await page.keyboard.up('ArrowLeft');
			console.log('[driver] ArrowLeft UP');
			await page.waitForTimeout(2000);
		} else {
			await page.waitForTimeout(SECONDS * 1000);
		}
	} finally {
		await browser.close();
	}
})().catch((e) => { console.error('driver error:', e); process.exit(2); });
