# Example 06 Input from Character Set

This example will show you how to input using a charset.

see [basic example](https://github.com/forntoh/LcdMenu/tree/master/examples/SimpleInput/SimpleInput.md)

## Requirements

- Keyboard
- LcdDisplay

## Process

### 1. Define your charset (list of accepted/valid chars)

You also need to track the active index of the list

```cpp
// ../../examples/CharsetInput/CharsetInput.ino#L36-L40
```

### 2. Move to an ItemInput menu item

Use `up()` and/or `down()` to navigate to an `ItemInput`.

### 3. Enter edit mode

Execute `enter()` to go to edit mode. _(cursor will start blinking 😉)_

### 4. Use `up()` and `down()` to cycle through your charset

`drawChar(char c)` is used to dispay the character without storing the value, the value will be stored only when `type(char character)` is executed.

```cpp
// ../../examples/CharsetInput/CharsetInput.ino#L68-L80
```

### 5. Type the selected character

Use `menu.type(char character)` to type the selected character

```cpp
// ../../examples/CharsetInput/CharsetInput.ino#L87-L88
```

### 6. `menu.back()` will exit edit mode

The value of the menu item will be passed through to the callback function attached to this item.

Full example 👉 [.../examples/CharsetInput/CharsetInput.ino](https://github.com/forntoh/LcdMenu/tree/master/examples/CharsetInput/CharsetInput.ino)
