
## Maps

### COMBOS
`jk`: `ESC`
`sd`: `⇥` TAB
`l;`: `'` quote
`qw`: `⇪` Caps Word (auto-cancels at end of word)

CH-layer only (symbol layer):
`l;`: `_` underscore
`./`: `` ` `` backtick

### BASE LAYER

```
╭─────┬───┬───┬───┬───┬───╮             ╭───┬───┬───┬───┬───┬───╮
│  ✗  │ q │ w │ e │ r │ t │             │ y │ u │ i │ o │ p │ ⌫ │
├─────┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│ CTL │ a │ s │ d │ f │ g │             │ h │ j │ k │ l │ ; │ ✗ │
│     │ ⌘ │ ⌥ │ ⇧ │ ⌃ │   │             │   │ ⌃ │ ⇧ │ ⌥ │ ⌘ │   │
├─────┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│ SFT │ z │ x │ c │ v │ b │             │ n │ m │ , │ . │ ; │ ✗ │
╰─────┴───┴───┴───┴───┴───╯             ╰───┴───┴───┴───┴───┴───╯
               ╭──────┬────┬─────╮ ╭─────┬─────┬─────╮
               │ 🌐/⌫ │ CH │ ⏎/C │ │ ␣  │ NUM │ ALT │
               ╰──────┴────┴─────╯ ╰─────┴─────┴─────╯
```

Home-row mods are symmetric (same finger → same mod on both hands):
pinky=⌘ Cmd, ring=⌥ Opt, middle=⇧ Shift, index=⌃ Ctrl. The `w`/`e` top-row
mod-taps are gone, and Shift is off the right thumb (Space is now a plain tap) —
shifting moves to the middle-finger home-row mod.

`✗` = disabled: `⇥` TAB moved to the `qw` combo, `'` moved to the `l;` combo, and
the bottom-right `RALT` (🌐 Globe) corner is gone — Globe now lives on the **left
thumb** (hold = 🌐 Globe / tap = `⌫` BSPC). macOS remaps Right-Alt → 🌐 in
*Keyboard → Modifier Keys*, so the firmware just sends `RALT`. Window tiling =
🌐(left thumb) + Ctrl(`f`, also a mod on NUM) + NUM(right thumb) + arrow.
Note: Backspace is **tap-only** now (no hold-to-repeat). Outer pinky
`CTL`/`SFT`/old-`⌫` remain as crutches until they're disabled too.


### NUMBERS AND ARROWS (NUM)

```
╭─────┬───┬─────┬─────┬─────┬───╮             ╭───┬───┬───┬───┬───┬───╮
│  ⇥  │ 1 │  2  │  3  │  4  │ 5 │             │ 6 │ 7 │ 8 │ 9 │ 0 │ ⌫ │
├─────┼───┼─────┼─────┼─────┼───┤             ├───┼───┼───┼───┼───┼───┤
│ CTL │   │ SFT │ ALT │ CTL │   │             │ ← │ ↓ │ ↑ │ → │   │   │
├─────┼───┼─────┼─────┼─────┼───┤             ├───┼───┼───┼───┼───┼───┤
│ SFT │   │     │     │     │   │             │   │   │   │   │   │   │
╰─────┴───┴─────┴─────┴─────┴───╯             ╰───┴───┴───┴───┴───┴───╯
                     ╭─────┬────┬─────╮ ╭─────┬─────┬─────╮
                     │ CMD │ FN │ ENT │ │ SPC │ --- │ ALT │
                     ╰─────┴────┴─────╯ ╰─────┴─────┴─────╯
```


### SPECIAL CHARACTERS (CH)

```
╭─────┬───┬───┬───┬───┬───╮             ╭───┬───┬───┬───┬───┬───╮
│  ⇥  │ ! │ @ │ # │ $ │ % │             │ & │ * │ ( │ ) │ ^ │ ⌫ │
├─────┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│ CTL │   │   │   │   │   │             │ | │ = │ [ │ ] │ - │ _ │
├─────┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│ SFT │   │   │   │   │   │             │ ~ │ + │ { │ } │ \ │ ` │
╰─────┴───┴───┴───┴───┴───╯             ╰───┴───┴───┴───┴───┴───╯
               ╭─────┬────┬─────╮ ╭─────┬─────┬─────╮
               │ CMD │ -- │ ENT │ │ SPC │ FN  │ ALT │
               ╰─────┴────┴─────╯ ╰─────┴─────┴─────╯
```


### FUNCTION KEYS AND MOUSE

```
╭────┬────┬────┬────┬────┬────╮             ╭────┬────┬────┬─────┬─────┬─────╮
│ ✗  │ F2 │ F3 │ F4 │ F5 │ F6 │             │ F7 │ F8 │ F9 │ F10 │ F11 │  ✗  │
├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼─────┼─────┼─────┤
│    │ F1 │ Vo │ V- │ V+ │    │             │ ←  │ ↓  │ ↑  │  →  │ F12 │     │
├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼─────┼─────┼─────┤
│ ✗  │ BT │    │ B+ │ B+ │    │             │    │ LC │ RC │     │     │     │
╰────┴────┴────┴────┴────┴────╯             ╰────┴────┴────┴─────┴─────┴─────╯
                   ╭─────┬────┬─────╮ ╭─────┬─────┬─────╮
                   │ CMD │ -- │ ENT │ │ SPC │ --- │ ALT │
                   ╰─────┴────┴─────╯ ╰─────┴─────┴─────╯
```

`BT`: Put keyboard into bootloader mode.  
`Vo`: Volume off  
`V-`: Volume down  
`V+`: Volume up  
`B-`: Brightness down  
`B+`: Brightness up  
`LC`: Left mouse click  
`RC`: Right mouse click  

