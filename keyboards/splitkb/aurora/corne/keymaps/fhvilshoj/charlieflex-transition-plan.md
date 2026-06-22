# Corne → Koepckeae Transition Plan

A staged plan to retrain my muscle memory onto a ~34-key mental model **on my
existing Corne**, so that when the Koepckeae is built I can type on it from
day one. The trick: keep all the Corne's physical keys, but progressively
neutralize the keys that won't exist on the Koepckeae, one capability at a
time, so my hands reorganize around the smaller set before the new board arrives.

> **Target switched Charlieflex → Koepckeae** (`ssbb/koepckeae`). The Koepckeae is a
> 34-key unibody with **4 thumbs** (2L/2R) and a full 3×5 grid, vs. the Charlieflex's
> ~32 keys / 3 thumbs / trimmed inner index. The extra thumb lets **Hyper/Alt keep its
> own key** (no one-shot-combo hack) and the full grid means **`b`/`n` stay put** (no
> Step 5). Same 5-column, symmetric-HRM core; strictly simpler, and the endgame
> collapses to one 34-key model for commuter + desk. Charlieflex kept below as the
> considered alternative.

---

## Context

|                           |                                                                                                                                                                                               |
| ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Current board**         | Aurora Corne — 42 keys (`LAYOUT_split_3x6_3`), wired, QMK                                                                                                                                     |
| **Target commuter board** | Koepckeae (`ssbb/koepckeae`) — 34-key unibody split (3×5 + 2 thumbs/hand), wireless (XIAO nRF52840), ZMK, Choc hotswap, splay + spaced thumbs                                                  |
| **Why**                   | Two-piece split is unstable on a train/plane tray table; want a stable one-piece board with built-in splay for slightly wider elbows in cramped spaces. Corne stays for wide-spread desk use. |
| **Firmware shift**        | QMK C (`keymap.c`) → **ZMK devicetree** (`.keymap`). Logic ports cleanly; syntax does not.                                                                                                    |
| **Endgame**               | Retire the Corne for a 34-key wireless Choc split (wide desk driver) + the Koepckeae (commuter) — **both are 34-key 3×5+2, so ONE identical mental model**, flashed from one ZMK keymap.       |
| **Considered**            | Charlieflex (`ctranstrum/chuck`) — ~32 keys / 3 thumbs / trimmed inner index. Rejected: the 3rd-thumb shortage forced Hyper into a combo and the inner-index cut forced `b`/`n` onto combos; the Koepckeae's 4th thumb + full grid avoid both. Notes retained below. |

### What the Koepckeae constrains the target layout to

- **5 columns per hand** — no outer pinky column.
- **Full 3×5 grid** — the inner index keeps all 3 keys, so `b`/`n` stay put.
- **4 thumbs total** (2 left / 2 right) — room for CH, NUM, Globe, Hyper holds + Enter/Space taps.
- Therefore: **symmetric home-row mods** + a few **combos** absorb the lost outer column; the thumbs absorb the rest with no combo hacks.

### What changes vs. my current `keymap.c` (summary)

1. **Outer pinky column disappears** (6 keys). Standalone `CTL`/`SHFT`/`RALT` there are already redundant with my mods; the real casualties are `TAB`, `BSPC`, `'`.
2. **Thumbs 6 → 4**. Fold the layer-holds in, but Globe and Hyper/Alt each keep a real thumb.
3. **Home-row mods become load-bearing and must be symmetric** — right home row currently has _no_ mods. This is the single biggest motor change.
4. **`b`/`n` stay put** — the Koepckeae keeps the full inner index (no relocation; Step 5 is gone).
5. **A few combos** recover the outer column (`TAB`, `'`) and add conveniences (`BSPC`, Caps Word). (`jk → ESC` already exists and stays.)

### What this plan can NOT rehearse

The Koepckeae's physical **splay and spaced-out thumb cluster**. The Corne's columns and thumbs stay put, so the _logical_ model will be identical but the fingertips will feel the geometry on day one. That's a comfort adjustment, not a re-learning.

---

## Operating principles

- **One change per ~1–2 weeks.** Don't stack. Each step feels awkward for a few days → normal → _then_ advance.
- **Hardest first, while crutches still exist.** Symmetric home-row mods go first while every other key is still where I expect it.
- **Never get stuck.** Each step adds the new home _before_ removing the old key, so I can always fall back by reverting one line.

---

## Step 1 — Symmetric home-row mods; kill the top-row mods

**Goal:** both hands modify independently (required once the outer mod column is gone).

- [x] Mirror left-hand GASC onto the right home row (same finger → same mod):
    ```
    J = RCTL_T(KC_J)   K = RSFT_T(KC_K)   L = RALT_T(KC_L)   ; = RGUI_T(KC_SCLN)
    ```
- [x] Revert top-row mod-taps to plain letters: `RCTL_T(KC_W) → KC_W`, `RALT_T(KC_E) → KC_E`.
- [x] **Drop Shift-on-Space thumb** (`MT(MOD_LSFT, KC_SPC) → KC_SPC`): pulled
      forward from Step 4 so shifting moves to the new middle-finger home-row mod
      immediately, while the motor change is already being learned.
- [ ] Run for the **longest** stretch of any step — this is the deepest motor change.

_Safe to do first: it's additive (gain right-hand mods, lose nothing essential)._

---

## Step 2 — Pre-place TAB, BSPC, and `'` (keep old keys as a crutch)

**Goal:** give the three genuine casualties (`TAB`, `BSPC`, `'`) their new homes while the outer column still works.

- [x] **BSPC → left outer thumb** (was plain `LGUI`; Gui is now covered by `A` and `;` home-row mods).
- [x] **TAB → left-hand combo** — now `S`+`D` (`COMB(SD_TAB, KC_TAB, LALT_T(KC_S), LSFT_T(KC_D))`); moved off `Q`+`W` because the home-row pair is comfier and `Q`+`W` freed up for **Caps Word** (`COMB(QW_CAPS, CW_TOGG, KC_Q, KC_W)`, needs `CAPS_WORD_ENABLE`) — handy since home-row-mod Shift makes long runs of capitals awkward; auto-cancels at word end and keeps `_`/digits (ideal for `SCREAMING_SNAKE`). `S`+`D` chosen over the `A`+`S` mirror of `'` because `as/ask/last/fast` would misfire as TAB; `sd` is a near-nonexistent bigram.
- [x] **`'` → combo** `L`+`;` (`COMB(LSCLN_QUOT, KC_QUOT, RALT_T(KC_L), RGUI_T(KC_SCLN))` — mod-tap keycodes per the Step 2 caveat).
- [x] **Disabled the base-layer `TAB` and `'` keys early** (`XXXXXXX`) — pulled forward from Step 3 to force the combos immediately. Outer `CTL`/`SFT`/`RALT`/`BSPC` stay as crutches; only TAB and `'` go dark for now.
- [ ] Consciously start reaching for the new homes. Outer keys still work as backup.

> ⚠️ **Combos must use the home-row-mod keycode, not the bare letter.** QMK matches
> combos against the _exact_ keycode sitting in the keymap at each position. Since
> Step 1, `j k l ;` are mod-taps, so a combo over them needs the wrapped form —
> e.g. `RALT_T(KC_L), RGUI_T(KC_SCLN)` for `l+;`, **not** `KC_L, KC_SCLN`. Using the
> bare letter compiles fine but the combo silently never fires. (This is exactly
> what broke `jk → ESC` after Step 1.) `q+w` is safe as plain `KC_Q, KC_W` — those
> aren't mods. Rule of thumb: if either key in a combo is a home-row mod, wrap it.

---

## Step 3 — Disable the entire outer pinky column

**Goal:** force the hands into the 5-column world.

- [x] **No-op the outer pinky column on every layer.** Done across BL / NUM / CH / FN —
      both hands, all rows are `XXXXXXX`. The board is now logically **5 columns per hand**.
      Nothing irreplaceable was lost; each casualty had a home first:
    - `TAB` → `s+d` combo · `'` → `l+;` combo · `RALT`(🌐) → left thumb (see below)
    - `_` / `` ` `` (CH) → `l;` / `./` combos — old CH outer positions now disabled
    - `LCTL` / `LSFT` (all layers) → redundant with home-row mods, just removed
    - `BSPC` (right-top, all layers) → removed; lives on the left thumb now
    - `F1` / `F12` / `QK_BOOT` (FN) → relocated inward (`F1`→under `F2`,
      `F12`→under `F11`, `QK_BOOT`→one right) before clearing the column
- [x] Moment-of-truth step survived — landed quickly because Steps 1–2 pre-placed the homes.

### 🌐 Globe / `fn` — resolved: **mod-tap on the left thumb**

The bottom-right `RALT` was my macOS Globe key (Right-Alt → 🌐 remapped in _Keyboard →
Modifier Keys_; QMK can't emit Apple's Globe HID usage, so it just sends `RALT`).
Disabling the outer column kills that corner, so Globe needs a holdable home that
chords with the NUM-layer arrows (window tiling = 🌐 + Ctrl + arrow).

- [x] **Left outer thumb → `RALT_T(KC_BSPC)`** (tap = `⌫` BSPC, hold = 🌐 Globe).
- [x] **Disable the old `RALT` corner** (`XXXXXXX`).
- Tiling chord splits across both hands, no collisions: 🌐(left thumb) +
  Ctrl(`f`, a plain mod on the NUM layer) + NUM(right thumb) + arrow(right hand).
  Also covers `fn`+arrows (Home/End/PgUp/Dn), `fn`+Delete, emoji, etc.
- **Tradeoff (resolved):** the thumb Backspace is tap-only (its hold is Globe). The
  awkward thumb reach + missing hold-to-repeat is fixed by a **`j`+`l` combo → `KC_BSPC`**
  (`COMB(JL_BSPC, KC_BSPC, RCTL_T(KC_J), RALT_T(KC_L))`): tap deletes, **hold repeats**
  (the combo holds the key down, so OS typematic kicks in). `jl` never rolls in normal
  English, so no mid-word misfires. The thumb BSPC stays as a harmless backup.

---

## Step 4 — Collapse six thumbs down to four

**Goal:** match the Koepckeae thumb count (2L/2R); fold the layer-holds in while keeping Globe and Hyper on their own thumbs.

Current cluster: `GUI · MO(CH) · Ctrl/Enter` ‖ `Shift/Space · MO(NUM) · Hyper/Alt`

- [x] Re-map to layer-taps + tri-layer. **Keep the two closest thumbs per hand
      (inner + middle); disable the outer edge** — the outer thumb is too long a reach:
    ```
    left  outer thumb:  XXXXXXX                // disabled — too far
    left  mid   thumb:  MO(CH)                 // CH momentary — no tap (BSPC is now the j+l combo)
    left  inner thumb:  MT(MOD_RALT, KC_ENT)   // 🌐 Globe on hold, Enter on tap   ← Globe took the Enter key
    right inner thumb:  LT(NUM, KC_SPC)         // numbers on hold, Space on tap
    right mid   thumb:  MT(MOD_HYPR, KC_LALT)   // Hyper on hold, Alt on tap
    right outer thumb:  XXXXXXX                // disabled — too far
    FN layer:           tri-layer — hold CH + NUM together to reach FN
    ```
- [x] **Drop the thumb Backspace.** BSPC now lives on the `j+l` combo (tap + hold-repeat),
      so the CH thumb needs no tap → plain `MO(CH)` (instant-on, matches today). Frees the
      tap slot and removes the awkward thumb reach that prompted the combo.
- [x] Disable the **two** now-unused thumb positions — left-**outer** + right-**outer** (`XXXXXXX`).
- [x] Wire the FN tri-layer in `keymap.c`: `layer_state_set_user → update_tri_layer_state(state, CH, NUM, FN)` (the old `MO(FN)` thumb is gone). Compiles, 94% flash.

**Which 4 thumbs survive (inner + middle, not inner + outer).** First cut kept the
inner + outer pair, but the outer thumb is too long a reach. So the four live thumbs
are the **two closest per hand**: inner (Enter/Globe ‖ Space/NUM) + middle (CH ‖ Hyper),
with the outer edge `XXXXXXX`. Bonus: **CH lands back on the left-middle thumb** where it
sat before Step 4 — that's the same position years of muscle memory already know.

**Globe ↔ Enter (the held layout).** CH keeps its middle thumb; Globe rides on the
inner thumb's hold (Enter on tap), replacing the dropped Ctrl-on-Enter (Ctrl is covered
by the home-row mod on `f`). Nothing prohibits it:

- Globe is still a held mod → window tiling is unchanged: 🌐(left-inner thumb) + Ctrl(`f`)
    - NUM(right-inner thumb) + arrow — both inner thumbs + index, no collision.
- The FN tri-layer only needs CH+NUM held; which thumb each sits on doesn't matter.
- Globe-on-Enter-hold is the same tap-hold shape as today's Ctrl-on-Enter, and an
  accidental Globe+key is _less_ destructive than the accidental Ctrl+key it replaces.

_Shift-on-Space and Ctrl-on-Enter holds being dropped are already covered by the new symmetric home-row mods._

### `Hyper` — kept on its own thumb (the 4-thumb win)

With 4 thumbs there's no shortage, so Hyper keeps its own thumb:
**`MT(MOD_HYPR, KC_LALT)`** on the right-**middle** thumb — Hyper on hold, Alt on tap. No
one-shot-combo hack, no four-mod chord: hold the thumb and tap the app key, as I do now.
This is the concrete payoff of choosing the Koepckeae over the Charlieflex. (It shifts
one position in from today's right-outer corner, since the outer thumb is now disabled.)

- [x] Keep Hyper on its own thumb — `MT(MOD_HYPR, KC_LALT)`, now on the right-**middle** thumb.

_(Optional, later)_ For even smoother app-switching, the old Charlieflex idea still works
as an **add-on**: a one-shot into an `APPS` layer where each key = `HYPR(key)`, fired by a
combo (`OSL(APPS)` / ZMK `&sl APPS`). Not needed for parity — Hyper already has a real key —
so it's parked. The full one-shot design is in git history if I revisit it.

---

## Step 5 — ~~Trim the inner index column~~ (retired — Koepckeae keeps `b`/`n`)

**Obsolete on the Koepckeae.** It keeps the full 3×5 grid, so `b`/`n` stay as normal keys —
no relocation, no combos, nothing to disable. This step only existed for the Charlieflex's
trimmed inner index. **The transition now ends at Step 4.**

**End state:** the Corne is _logically_ a 34-key board — 5 columns, **full 3×5 grid (`b`/`n` kept)**, **four thumbs**, symmetric home-row mods, combos for TAB/`'`/ESC/BSPC/Caps-Word, and SPC/ENT/Globe/Hyper/layers on thumbs. **This is the target mental model**, on hardware I've used the whole time.

### Target layout — the 34-key mental model (base layer)

What the hands actually use once the steps land. Only live keys are drawn; the
Corne's outer pinky column and two thumbs are gone (4 thumbs survive: 2L / 2R).
`b`/`n` stay (full 3×5). Home-row mods are symmetric (same finger → same mod on both hands).

```
╭───┬───┬───┬───┬───╮             ╭───┬───┬───┬───┬───╮
│ q │ w │ e │ r │ t │             │ y │ u │ i │ o │ p │
├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤
│ a │ s │ d │ f │ g │             │ h │ j │ k │ l │ ; │
│ ⌘ │ ⌥ │ ⇧ │ ⌃ │   │             │   │ ⌃ │ ⇧ │ ⌥ │ ⌘ │
├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤
│ z │ x │ c │ v │ b │             │ n │ m │ , │ . │ / │
╰───┴───┴───┴───┴───╯             ╰───┴───┴───┴───┴───╯
          ╭──────┬─────────╮ ╭─────────┬─────────╮
          │  CH  │ ⏎ · 🌐  │ │ ␣ · NUM │ ⌥ · Hyp │
          ╰──────┴─────────╯ ╰─────────┴─────────╯
          (2 left thumbs)     (2 right thumbs)
```

- **Home-row mods** (hold): pinky=⌘ · ring=⌥ · middle=⇧ · index=⌃, both hands.
- **Thumbs**:
    - left outer → **CH** symbols layer (momentary hold; no tap — BSPC is the `j+l` combo)
    - left inner → `⏎` Enter (tap) · **🌐 Globe / RALT** (hold)
    - right inner → `␣` Space (tap) · **NUM** numbers/arrows layer (hold)
    - right outer → `⌥` Alt (tap) · **Hyper** ⌃⌥⇧⌘ (hold) — its own key again, as today (needs the 4th thumb)
    - hold **CH + NUM together** → **FN** layer (tri-layer)
- **Window tiling** = 🌐(left inner thumb) + Ctrl(`f`) + NUM(right thumb) + arrow. macOS
  remaps Right-Alt → 🌐 in _Keyboard → Modifier Keys_; firmware just sends `RALT`.
- **Combos** recover everything the lost keys did:

    | Combo                | Sends                     | Recovers                                              |
    | -------------------- | ------------------------- | ----------------------------------------------------- |
    | `s`+`d`              | `⇥` TAB                   | killed outer column                                   |
    | `l`+`;`              | `'` quote                 | killed outer column                                   |
    | `j`+`k`              | `ESC`                     | (already exists)                                      |
    | `j`+`l`              | `⌫` Backspace             | replaces the thumb BSPC — tap deletes, hold repeats   |
    | `q`+`w`              | `⇪` Caps Word             | (new convenience — HRM Shift makes long caps awkward) |
    | `l`+`;` _(CH layer)_ | `_` underscore            | CH outer column                                       |
    | `.`+`/` _(CH layer)_ | `` ` `` backtick          | CH outer column                                       |

> The one thing this picture can't show is _feel_: on the Koepckeae the board splays
> outward and the thumbs sit spaced apart. The logical model above is identical —
> only the fingertips will notice the geometry on day one.

---

## Progress tracker

| Step | Change                            | Started    | "Feels normal"         | Notes                                                                                                                                                                                                                                              |
| ---- | --------------------------------- | ---------- | ---------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1    | Symmetric HRM + drop top-row mods | 2026-06-15 | Wednesday, 2026-Jun-17 | Right home row now CTL/SFT/ALT/GUI on j/k/l/;; w/e top-row mods reverted to plain; Shift-on-Space thumb dropped (pulled fwd from Step 4)                                                                                                           |
| 2    | Pre-place TAB / BSPC / `'`        | 2026-06-15 |                        | BSPC→left outer thumb; TAB→combo (now on `sd`); `'`→`l;` combo. Base-layer TAB+`'` disabled early                                                                                                                                                  |
| 3    | Disable outer pinky column        | 2026-06-16 |                        | **Done 2026-06-17.** Outer column fully `XXXXXXX` on all 4 layers → logical 5-col board. 🌐 Globe→left thumb (`RALT_T(KC_BSPC)`, tap-only BSPC); F1/F12/QK*BOOT relocated inward on FN; `*`/`` ` ``→CH combos; TAB moved `qw`→`sd`; `qw`→Caps Word |
| 4    | Six thumbs → four (2L/2R)         | 2026-06-22 |                        | **Implemented 2026-06-22** (compiles, 94% flash). Kept **inner + middle** thumbs (outer edge too far → `XXXXXXX`); CH back on left-mid, Hyper/Alt on right-mid (`MT(MOD_HYPR, KC_LALT)`); Globe on left-inner Enter hold; thumb BSPC dropped (now the `j+l` combo); FN now a `update_tri_layer_state` (CH+NUM). No Apps-combo hack needed. |
| 5    | ~~Trim inner index~~              | —          | —                      | **Retired** — Koepckeae keeps the full 3×5, so `b`/`n` stay. Transition ends at Step 4.                                                                                                                                                            |

---

## Endgame: one 34-key model across desk + commuter

Once the 34-key model is locked, the 42-key Corne is carrying ~8 keys my hands no
longer use — natural to retire it for a **34-key wireless Choc split** as the _wide_
desk driver, with the **Koepckeae** as the commuter.

- Candidate wide boards: **Aurora Sweep, Cantor (Remix), Chocofi, Urchin** (all 34-key, wireless-capable, Choc).
- **Same key count everywhere.** The Koepckeae and any 34-key split are both 3×5+2, so it's **literally one keymap, one mental model** — no spare-key fudging (the Charlieflex's 32-vs-34 mismatch is gone).
- Result: one model across three boards — wide split at the desk, Koepckeae on the train, original Corne as backup/sale.

---

## Reference configs & reading

- **`JeffDess/zmk-config`** — runs a Corne (36) and Urchin (34) off **one shared config**; proof that cross-board muscle memory works. Best "use both" model.
- **`nickfaraco/zmk-config`** — Chocofi 34/36, based on **urob's** keymap; shows symbols/parens recovered as combos.
- **`ferrance/dizave42`** — honest "why I stopped at 42 / Miryoku tradeoffs" account.
- **Miryoku** — canonical 36-key reference layout.
- **urob's ZMK config** — the "timeless home-row mods" everyone copies.
- **`ssbb/koepckeae`** — **target board.** 34-key unibody, ZMK, Choc hotswap, splay + spaced thumbs; inspired by Pete Johanson's Zaphod Lite. Read its `config/` for the ZMK shield + default keymap.
- **`ctranstrum/chuck` (`zmk` branch)** — _considered alternative_ (Charlieflex). The author's **"Twentyone Chuck Street"** layout is still a good reference for a 3-thumb / trimmed-index design and ZMK Studio live-remap.

---

## Next artifacts to generate (optional)

- [x] Drop-in `keymap.c` revision for Step 4 (the 6→4 thumb collapse) — **done & flashing-ready** (2026-06-22).
- [ ] Matching ZMK `.keymap` for the end state, so the eventual Koepckeae/split flash is copy-paste.
