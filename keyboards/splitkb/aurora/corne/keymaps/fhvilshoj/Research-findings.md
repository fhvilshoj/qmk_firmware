# The Best Wireless Unibody Splay Keyboards for Commuting: A Prioritized Top 10

## TL;DR
- **The single best fit is the Charlieflex (ctranstrum "chuck") — a genuine one-piece unibody with built-in splay, wireless ZMK on a Seeed XIAO nRF52840, and low-profile Choc — designed by its creator specifically because separated split halves shift around when you move; its only real miss is a low 30–32 key count.** If you want to stay closer to your Corne's 42 keys, the 34-key **koepckeae** and **Osprette V3**, the 36-key **Lapka**, and the 41-key **REVIUNG41** are the strongest unibody alternatives.
- **Critical correction:** the TOTEM and the Lintilla — both frequently suggested for travel — are **two-piece splits, not unibody**, so they do NOT solve your "two halves are unstable on a laptop" problem. They belong in "other options," not the core list.
- **The inherent tradeoff:** a unibody physically cannot spread your hands as wide as your separated Corne. What it CAN do is angle (splay) the two key clusters outward by a fixed amount so your wrists are straighter than on a flat laptop board — keep the Corne for true wide-elbow spread, use a unibody for stable, slightly-splayed commuting.

## Key Findings
- True unibody (monoblock) boards use a **single controller**, so they have no inter-half Bluetooth pairing, no split-latency, simpler/longer battery life, and nothing to reposition — exactly what you want on a tray table.
- Almost every good fit runs **ZMK** on a **Seeed XIAO nRF52840 (XIAO BLE)** or a **nice!nano v2**; these are the two dominant wireless controllers.
- Splay on a flat unibody is in the **horizontal plane only** (columns/halves rotated), which is exactly compatible with your "splay but stay flat, no tenting" requirement.
- There is no major-vendor commercial unibody wireless Choc board with splay; this space is DIY/open-source. Commercial low-profile boards (NuPhy, Keychron, Lofree) are unibody but have a number row and no splay; the ZSA Voyager and splitkb Aurora Sweep are two-piece.

## Details — The Prioritized Top 10

### 1. Charlieflex (repo name "chuck") — by Chad Transtrum
- **Why #1:** It is the rare board purpose-built for your exact complaint. The designer explicitly created it after disliking separate-halves splits because "I move around a bit as I type so I either have to keep adjusting the position of each half, or I end up contorting my wrists." It is a true unibody, wireless-first, with splay, an ultra-low Choc profile, and an optional encoder.
- **Requirements:** Wireless ✓ (XIAO BLE, ZMK). Unibody ✓. Splay ✓ ("when fingers extend, they splay, so the keys also splay outward to follow the fingers"). Flat ✓ (low-profile Choc, no tenting). Choc ✓. Hotswap — build-dependent (diodeless design; commonly direct-solder). Compact — 30–32 keys, which is SMALLER than your stated 34 floor; this is its main miss.
- **Layout:** ~31 keys; reduced inner column, aggressive pinky stagger, 1 thumb key per hand (optional 2nd).
- **Sourcing/build:** GitHub `ctranstrum/chuck`. Ergogen + KiCad source and gerbers in repo → order PCB at JLCPCB (5 boards ~$10–15). Case STLs in repo for FDM printing; comes in 1-/2-thumb variants. Controller: Seeed XIAO BLE (wireless) or XIAO RP2040 (wired). ZMK config in repo. Difficulty: intermediate (XIAO castellated soldering). Cost DIY: ~$50–70.

### 2. koepckeae — by ssbb
- **Why #2:** Of boards that hit EVERY hard requirement at a sensible key count, this is the cleanest. It is a 34-key unibody split with splay, hotswap Choc, and wireless ZMK.
- **Requirements:** Wireless ✓ (nice!nano, ZMK). Unibody ✓. Splay ✓. Flat ✓. Choc + hotswap ✓. Compact ✓ (34 keys, your floor). Spaced-out thumbs (more comfortable thumb reach than Corne's tucked cluster).
- **Sourcing/build:** GitHub `ssbb/koepckeae`. Heavily inspired by Pete Johanson's Zaphod Lite. KiCad/gerbers → JLCPCB. nice!nano v2; max battery 29×21×8 mm. Choc v1 hotswap sockets. 3D-printed case files in repo. ZMK config provided. Difficulty: intermediate. Cost DIY: ~$70–90.

### 3. Osprette V3 — by Sam Mohr (smores56)
- **Why #3:** The most documented, "known-good" unibody splay board in the community at 34 keys, with explicit splay geometry — but it is direct-solder (no hotswap), which is its only requirement miss.
- **Requirements:** Wireless ✓ (Pro Micro-compatible daughterboard; nice!nano gives BT; battery terminals + power switch on PCB). Unibody ✓. Splay ✓ — the V2 documents "Splay (4° between middle and ring, 8° between ring and pinky)"; V3 keeps the same lineage with increased pinky stagger. Flat ✓. Choc ✓. Hotswap ✗ — "direct solder (AKA no hotswap) for maximum stability." Compact ✓ (34 keys).
- **Sourcing/build:** GitHub `smores56/osprette-v3`. Upload `osprette_v3.zip` to JLCPCB at 1.6 mm thickness (remove order number). Choc v1 direct-soldered. nice!nano v2 for wireless. QMK or ZMK. Difficulty: beginner-intermediate (no hotswap sockets to fiddle). Cost DIY: ~$60–80.

### 4. Visorbearer — by carrefinho
- **Why #4:** The most polished recent unibody wireless design, with hotswap Choc, splay, and classy dead-front RGB battery/Bluetooth indicators. Ranked below the above only because it is a work-in-progress and is geared to Choc v2 (with a third-pin caveat).
- **Requirements:** Wireless ✓ (XIAO nRF52840 Plus, ZMK). Unibody ✓ (32–34 keys, 5x3+2 with case/plate variants). Splay ✓. Flat ✓. Choc + hotswap ✓ — but note the PCB is "incompatible with older Choc v2 switches that have a third stabilizing pin"; newer Choc v2 (Lofree POM, Kailh Hide Mountain, etc.) work. Choc-spaced MX-stem keycaps are scarce (Taihao THCS, Asymplex Chicago Steno) — a real-world annoyance.
- **Sourcing/build:** GitHub `carrefinho/visorbearer` + `visorbearer-zmk-module`. 3D-printed case + switch plate with switch-puller grooves. ZMK shield via west manifest. Difficulty: intermediate. Cost DIY: ~$70–100.

### 5. CB34S — by bubbleology (designed with Mabroum)
- **Why #5:** A clean 34-key columnar unibody built explicitly to be wireless from the start, with optional nice!view display.
- **Requirements:** Wireless ✓ (nice!nano, ZMK). Unibody ✓. Splay — limited (column-staggered; less aggressive than Osprette/koepckeae). Flat ✓. Choc ✓. Compact ✓ (34 keys). Hotswap — supported in build.
- **Sourcing/build:** GitHub `bubbleology/CB34S`. KiCad source + gerber → JLCPCB. nice!nano + optional nice!view. Dedicated ZMK config repo. Difficulty: intermediate. Cost DIY: ~$70–90.

### 6. Zaphod Lite — by Pete Johanson
- **Why #6:** The original proof-of-concept for a low-profile wireless unibody split (2021), from a core ZMK maintainer; "Lite" is the hand-solderable open-source version. Mature firmware, but feature-focused (Sharp memory LCD) and only 34 keys.
- **Requirements:** Wireless ✓ (onboard nRF52840 on original; XIAO footprint on Lite; ZMK). Unibody ✓. Splay — Ferris-inspired, modest. Flat ✓. Choc ✓. Compact ✓ (34 keys).
- **Sourcing/build:** Build guide at docs.lpgala.xyz; Zaphod Lite is open-source and uses any XIAO footprint controller. Difficulty: intermediate. Cost DIY: ~$60–90 (kits have appeared via LP Galaxy).

### 7. Lapka — by Nikita Shirokov (braindefender)
- **Why #7:** A 36-key low-profile unibody with **uniform splay** and an extremely low case ("the switches almost touch the table"), matching your flatness obsession; closer to your key count than the 34s.
- **Requirements:** Wireless ✓ (SuperMini nRF52840, nice!nano-compatible; ZMK). Unibody ✓. Splay ✓ (uniform splay). Flat ✓✓ (ultra-low). Choc ✓. Compact ✓ (36 keys). Diodeless, direct-pin (so typically direct-solder, not hotswap).
- **Sourcing/build:** Featured at kbd.news/Lapka (KBD #190, April 2025). Open-source files; SuperMini nRF52840; ZMK. Difficulty: intermediate. Cost DIY: ~$50–70.

### 8. REVIUNG41 — by gtips
- **Why #8:** The closest key-count match to your Corne (41 vs 42), a long-established unibody, available as kits including a wireless nice!nano version. Ranked mid-pack because its splay is a gentle inward fan rather than aggressive columnar splay, and the mainstream kit is MX-hotswap (you must choose a Choc variant).
- **Requirements:** Wireless ✓ (beekeeb sells a "Wireless REVIUNG41 DIY Kit" with nice!nano v2). Unibody ✓. Splay — modest (column-staggered "split non-split" with slight angle). Flat — Choc variants are low-profile. Choc — requires the low-profile variant (cyril279's choc version; holykeebs sells a Choc Reviung41) rather than the default MX kit. Hotswap ✓. Compact ✓ (41 keys).
- **Sourcing/build:** Original by gtips; beekeeb wireless kit (PCB + nice!nano v2 + 12p sockets + 41 hotswap sockets + diodes + reset). For Choc + wireless, combine a Choc Reviung variant PCB with a nice!nano and ZMK. Difficulty: intermediate. Cost: beekeeb PCB-set tier ~$30 up to fuller kits; DIY ~$70–110.

### 9. Thumbsup! V11 — by ThumbsUpKeyboards (commercial-DIY hybrid, Etsy)
- **Why #9:** A genuinely unibody, wireless-capable, hotswap Choc board you can buy as a kit or assembled — convenient — but it is large (5×12 / 58 keys) and must be physically sawed down along provided slots to 4×10 to meet your compact requirement.
- **Requirements:** Wireless ✓ (nice!nano v2 + ZMK / ZMK Studio). Unibody ✓. Splay — raised/angled thumb cluster and index columns (a 3D-relief unibody, not pure flat). Choc + hotswap ✓. Compact ✗ by default (sawable to 4×10).
- **Sourcing/build:** Etsy "Thumbsup! V11." Sold as bare PCB, hotswap-socketed board, or DIY kit. nice!nano + 110 mAh battery + power switch option; ZMK preinstalled. Difficulty: low (assembled) to intermediate (kit). Cost: roughly mid-hundreds depending on options.

### 10. ScottoWings — by Joe Scotto
- **Why #10:** The flattest handwired unibody available ("less than 20 mm tall"), fully open and cheap — but it is **wired by default** (RP2040 Zero / Pro Micro), so it only meets your #1 wireless requirement if you handwire a nice!nano yourself. Ranked last for that reason.
- **Requirements:** Wireless — only via DIY substitution of a nice!nano (not the documented build). Unibody ✓. Splay — column-staggered monoblock, modest. Flat ✓✓ (thinnest here). Choc ✓ (18×17 mm spacing). Hotswap ✗ (handwired/direct). Compact ✓ (34/40 keys).
- **Sourcing/build:** scottokeebs.com + Joe Scotto's GitHub/YouTube handwiring tutorials. 3D-printed sandwich case STLs, copper wire, diodes, controller. QMK (ZMK if you swap to nice!nano). Difficulty: high (handwiring). Cost DIY: ~$40–60.

## Other Options Worth Mentioning

**Two-piece splits often mislabeled as travel-unibody (do NOT meet your core requirement, but excellent boards):**
- **TOTEM (GEIGEIGEIST)** — a 38-key column-staggered split with splay, wireless ZMK on dual XIAO BLE, hotswap Choc. It won first prize in the Seeed Fusion DIY XIAO Mechanical Keyboard Contest in 2022 and is hugely popular, but it is **two separate halves**, so it reproduces the exact instability you're trying to escape. Kits: keeb.supply GEIST TOTEM **€114.00–€158.00** (optional assembly +€84.00); beekeeb "Pre-soldered Wireless TOTEM 38 keys" **USD $248.00** (reduced from $258.00); ergomech aluminum "Executive Edition" assembled ~$243. Consider only if you reconsider the unibody requirement.
- **Lintilla (Chad Transtrum)** — 42-key wireless split with aggressive splay and a 7 mm case; the designer's own follow-up (the Charlieflex, #1 above) exists precisely because Lintilla's separate halves annoyed him. Two-piece.
- **Aurora Sweep (splitkb.com)** — 34-key, wireless-capable (nice!nano + Wireless Expansion Kit), Choc hotswap — but two-piece; splitkb sells no unibody board.

**Other genuine unibody DIY boards (less documented or niche):** MonoSeb40 (seblov, 40-key wireless monoblock), Re-gret/Egret (Ryan Schenk, unibody with splay), Jack32 (Jerome Olivier, low-pro monoblock, single thumb), Alias (dohn-joh, monoblock split with wireless dongle), Birdie6 (choochuwu, 36-key monoblock with an aggressive 80° between halves — but MX-only and wired), and Reviung34 (smaller Reviung).

**Commercial off-the-shelf (flag: not DIY):**
- **ZSA Voyager** — 52-key, hotswap Choc v1, beautifully flat (the case is only 8 mm thick excluding switches and keycaps) with a magnetic steel base and tripod mounts; the build quality is the best here. But it is **wired-only (QMK, TRRS between halves)** and **two-piece**, so it fails both your wireless and unibody requirements. $365 including shipping with a 2-year warranty. Excellent if you relax those constraints.
- **NuPhy Air75 V3** — unibody, low-profile, wireless, **$139.95** on NuPhy's web store; but it's an 84-key 75% board (13.2 mm front height, 4,000 mAh battery) with a number row and **no splay** — fails compact + splay.
- **Keychron low-profile / Lofree Flow** — same category as NuPhy: unibody, no splay, number row (e.g. the Lofree Flow84 at ~$149.99 on Amazon).
- **MoErgo Glove80 / Kinesis** — sculpted/tented and large; fail your flat + compact requirements.

## Recommendations
1. **Build the Charlieflex first if you can live with ~31 keys**, or the **koepckeae / Osprette V3 if you want to stay at 34 keys** with splay. These three are the purest expression of "wireless + unibody + splay + flat + Choc." Order PCBs from JLCPCB (gerbers in each GitHub repo), pair with a Seeed XIAO BLE (Charlieflex/koepckeae) or nice!nano (koepckeae/Osprette), 3D-print the case STLs, and flash the repo's ZMK config.
2. **If proximity to your Corne's 42-key muscle memory matters more than maximum splay**, build a **Choc REVIUNG41** (41 keys, hotswap) with a nice!nano — you'll keep nearly the same layout in one rigid piece.
3. **Decision thresholds that would change the pick:**
   - If you find 34 keys cramped after a week → move to REVIUNG41 (41) or Lapka (36).
   - If hotswap turns out to be essential → drop Osprette V3 (direct-solder) for koepckeae or Visorbearer.
   - If you want a buy-don't-build path → Thumbsup! V11 (sawed to 4×10) or, abandoning the wireless+unibody constraints, a ZSA Voyager.
4. **Manage expectations on elbows:** even the most aggressively splayed unibody (Birdie6's 80°, Osprette's 4°/8° pinky splay) cannot give you the wide-elbow spread of a separated Corne. Treat the unibody as a stability/wrist-angle upgrade over a flat laptop board, not a Corne replacement — which matches your stated intent.

## Caveats
- **Splay angle data is uneven.** The 4°/8° figure is verbatim from the Osprette **V2** README; V3 keeps the lineage but doesn't restate exact degrees. TOTEM's exact column-rotation degrees are not published in its repo (the designer only says "splay of the outside three columns"). Treat any specific angle as approximate unless you open the board's Ergogen `.yaml`.
- **Hotswap is not universal.** Osprette V3, Lapka, ScottoWings and most diodeless designs are direct-solder; Charlieflex's hotswap status is build-dependent. Confirm in each repo before ordering sockets.
- **Choc v2 keycap scarcity** affects Visorbearer specifically — choc-spaced MX-stem keycaps are limited as of late 2025 (effectively Taihao THCS and Asymplex Chicago Steno).
- **Battery life on unibody is simpler** (single controller, no peripheral-half drain), but exact runtime depends on battery size and any display/RGB; the indicator LEDs on Visorbearer and displays on CB34S/Zaphod cost power.
- **Vendor/stock volatility:** prices and availability (keeb.supply, beekeeb, ergomech, Etsy) shift month to month; verify current 2026 stock before buying.
- This space is DIY-dominated; none of the top-10 are mass-produced, so expect to source controllers, switches, batteries, and print/lasercut cases yourself.