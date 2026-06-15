# Corne → Charlieflex Transition Plan

A staged plan to retrain my muscle memory onto a ~32-key mental model **on my
existing Corne**, so that when the Charlieflex is built I can type on it from
day one. The trick: keep all the Corne's physical keys, but progressively
neutralize the keys that won't exist on the Charlieflex, one capability at a
time, so my hands reorganize around the smaller set before the new board arrives.

---

## Context

| | |
|---|---|
| **Current board** | Aurora Corne — 42 keys (`LAYOUT_split_3x6_3`), wired, QMK |
| **Target commuter board** | Charlieflex (`ctranstrum/chuck`) — ~31–32 keys, unibody, wireless, ZMK, Choc hotswap |
| **Why** | Two-piece split is unstable on a train/plane tray table; want a stable one-piece board with built-in splay for slightly wider elbows in cramped spaces. Corne stays for wide-spread desk use. |
| **Firmware shift** | QMK C (`keymap.c`) → **ZMK devicetree** (`.keymap`). Logic ports cleanly; syntax does not. ZMK Studio allows live remap without recompiling. |
| **Endgame** | Once the model is locked, retire the Corne for a 34-key wireless Choc split (wide daily driver) + Charlieflex (commuter), both flashed from **one ZMK keymap**. |

### What the Charlieflex actually constrains the target layout to
- **5 columns per hand** — no outer pinky column.
- **Inner index column cut to 2 keys** (no index stretch).
- **Pinky lowered**, top pinky key traded for a ring-finger key.
- **~3 thumbs total** (my build: 2 left / 1 right).
- Therefore: **symmetric home-row mods** + **combos/thumbs** must absorb everything the lost keys used to do.

### What changes vs. my current `keymap.c` (summary)
1. **Outer pinky column disappears** (6 keys). Standalone `CTL`/`SHFT`/`RALT` there are already redundant with my mods; the real casualties are `TAB`, `BSPC`, `'`.
2. **Thumbs 6 → 3**. Fold layer-holds into the keys they pair with via layer-taps.
3. **Home-row mods become load-bearing and must be symmetric** — right home row currently has *no* mods. This is the single biggest motor change.
4. **Inner index column loses one key per hand** (`B` / `N` relocate).
5. **More reliance on combos** to recover `TAB`, `'`, `B`, `N`, etc. (`jk → ESC` combo already exists and stays.)

### What this plan can NOT rehearse
The Charlieflex's physical **splay and lowered-pinky stagger**. The Corne's columns stay put, so the *logical* model will be identical but the fingertips will feel the geometry on day one. That's a comfort adjustment, not a re-learning.

---

## Operating principles
- **One change per ~1–2 weeks.** Don't stack. Each step feels awkward for a few days → normal → *then* advance.
- **Hardest first, while crutches still exist.** Symmetric home-row mods go first while every other key is still where I expect it.
- **Never get stuck.** Each step adds the new home *before* removing the old key, so I can always fall back by reverting one line.

---

## Step 1 — Symmetric home-row mods; kill the top-row mods
**Goal:** both hands modify independently (required once the outer mod column is gone).

- [ ] Mirror left-hand GASC onto the right home row (same finger → same mod):
  ```
  J = RCTL_T(KC_J)   K = RSFT_T(KC_K)   L = RALT_T(KC_L)   ; = RGUI_T(KC_SCLN)
  ```
- [ ] Revert top-row mod-taps to plain letters: `RCTL_T(KC_W) → KC_W`, `RALT_T(KC_E) → KC_E`.
- [ ] Run for the **longest** stretch of any step — this is the deepest motor change.

*Safe to do first: it's additive (gain right-hand mods, lose nothing essential).*

---

## Step 2 — Pre-place TAB, BSPC, and `'` (keep old keys as a crutch)
**Goal:** give the three genuine casualties their Charlieflex homes while the outer column still works.

- [ ] **BSPC → left outer thumb** (currently plain `LGUI`; Gui is now covered by `A` and `;` home-row mods).
- [ ] **TAB → left-hand combo** (e.g. `Q`+`W`) in the combo generator.
- [ ] **`'` → combo** (e.g. `L`+`;`) — too frequent for contractions to bury on a deep layer.
- [ ] Consciously start reaching for the new homes. Outer keys still work as backup.

---

## Step 3 — Disable the entire outer pinky column
**Goal:** force the hands into the 5-column world.

- [ ] No-op all six outer positions:
  ```
  left  outer:  TAB → XXXXXXX   LCTL → XXXXXXX   LSFT → XXXXXXX
  right outer:  BSPC → XXXXXXX   '   → XXXXXXX   RALT → XXXXXXX
  ```
- [ ] Moment-of-truth step. If too jarring, revert a single line. Usually lands within days because Step 2 pre-placed the homes.

---

## Step 4 — Collapse six thumbs down to three
**Goal:** match the Charlieflex thumb count; fold layer-holds into the keys they pair with.

Current cluster: `GUI · MO(CH) · Ctrl/Enter` ‖ `Shift/Space · MO(NUM) · Hyper/Alt`

- [ ] Re-map to layer-taps + tri-layer:
  ```
  left  inner thumb:  LT(CH, KC_ENT)     // symbols on hold, Enter on tap
  left  outer thumb:  KC_BSPC            // already moved here in Step 2
  right thumb:        LT(NUM, KC_SPC)    // numbers on hold, Space on tap
  FN layer:           tri-layer — hold CH + NUM together to reach FN
  ```
- [ ] Disable the two now-unused thumb positions (`XXXXXXX`).

*Shift-on-Space and Ctrl-on-Enter holds being dropped are already covered by the new symmetric home-row mods.*

### `Hyper` — resolved: **one-shot Apps layer**
Hyper is used aggressively for app switching and must stay ergonomic. Don't hold a
four-mod chord — tap a one-shot into a layer where each key sends the full Hyper combo.
With only 3 thumbs (all used) and the outer column gone, there's no spare key, so the
one-shot lives on a **combo** — costing zero keys and keeping `BSPC` a clean tap.

- [ ] Keep the **left-outer thumb** as plain `KC_BSPC` (no layer-tap needed now).
- [ ] Trigger the Apps layer as a **one-shot on a combo** (tap combo → tap app → fires once):
  ```c
  // QMK: OSL(APPS) on a combo (define in keymap_combo.h / combo source)
  // ZMK: &sl APPS on a combo
  ```
  Default combo: a comfortable, low-misfire pair (e.g. two adjacent non-mod keys like
  `C`+`V`, or both left thumbs). Combo position is easy to move — tune later.
- [ ] Add an `APPS` layer. Put **most-used apps on home row** as discrete Hyper combos;
  fill the rest so any key = `Hyper`+itself (keeps ad-hoc Hyper available):
  ```c
  // QMK: HYPR(kc) = Ctrl+Alt+Shift+Gui + kc
  [APPS] = LAYOUT_split_3x6_3(
      _______, HYPR(KC_Q), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), /* ... */
      _______, HYPR(KC_A), HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), /* ... */
      /* fill remaining keys with HYPR(KC_x) */
  )
  ```
- [ ] **ZMK equivalent** (for Charlieflex / future splits, one shared model):
  ```
  #define HY(key) LG(LC(LA(LS(key))))   // wrap any keycode in Hyper
  // one-shot trigger (combo):  &sl APPS
  // layer keys:  &kp HY(T)   &kp HY(S)   ...
  ```
- [ ] Fill in actual app → key map: ___________________________

*One-shot = tap, tap app, done — no hold, ideal for frequent single fires. For a run of
several Hyper combos, tap the combo again each time (or add a hold/toggle variant later).
Benefits: no four-mod chord ever pressed; app positions remappable independent of the
letter underneath; identical across Corne, Charlieflex, and future splits.*

---

## Step 5 — Trim the inner index column → parity
**Goal:** match the Charlieflex anti-stretch geometry.

- [ ] Relocate `B` and `N` (bottom-inner index) to a combo or layer.
- [ ] Disable those two positions on the Corne (`XXXXXXX`).

**End state:** the Corne is *logically* a ~32-key board — 5 columns, inner index of 2, three thumbs, symmetric home-row mods, combos for TAB/`'`/ESC/B/N, BSPC/SPC/ENT/layers on thumbs. **This is the Charlieflex mental model**, on hardware I've used the whole time.

---

## Progress tracker

| Step | Change | Started | "Feels normal" | Notes |
|------|--------|---------|----------------|-------|
| 1 | Symmetric HRM + drop top-row mods | | | |
| 2 | Pre-place TAB / BSPC / `'` | | | |
| 3 | Disable outer pinky column | | | |
| 4 | Six thumbs → three | | | Hyper → one-shot Apps layer (`OSL(APPS)` on a combo) |
| 5 | Trim inner index column | | | |

---

## Endgame: two small splits to companion the Charlieflex
Once the 32-key model is locked, the 42-key Corne is carrying ~10 keys my hands no
longer use — natural to retire it for a **34-key wireless Choc split** as the *wide*
daily driver, with the Charlieflex as the commuter.

- Candidate wide boards: **Aurora Sweep, Cantor (Remix), Chocofi, Urchin** (all 34-key, wireless-capable, Choc).
- Flash **all boards from one ZMK keymap.** A 34-key split has two *spare* keys vs. the Charlieflex's 32 — leave them as duplicates/conveniences. (The inverse of the "Miryoku wastes keys on a Corne" problem, and trivial.)
- Result: one mental model across three boards — wide split at the desk, Charlieflex on the train, original Corne as backup/sale.

---

## Reference configs & reading
- **`JeffDess/zmk-config`** — runs a Corne (36) and Urchin (34) off **one shared config**; proof that cross-board muscle memory works. Best "use both" model.
- **`nickfaraco/zmk-config`** — Chocofi 34/36, based on **urob's** keymap; shows symbols/parens recovered as combos.
- **`ferrance/dizave42`** — honest "why I stopped at 42 / Miryoku tradeoffs" account.
- **Miryoku** — canonical 36-key reference layout.
- **urob's ZMK config** — the "timeless home-row mods" everyone copies.
- **`ctranstrum/chuck` (`zmk` branch)** — Charlieflex firmware + the author's **"Twentyone Chuck Street"** default layout. Read `config/` / `boards/shields/`. Supports **ZMK Studio** (live remap).

---

## Next artifacts to generate (optional)
- [ ] Five drop-in `keymap.c` revisions (one per step), ready to flash in sequence.
- [ ] Matching ZMK `.keymap` for the end state, so the eventual Charlieflex/split flash is copy-paste.
