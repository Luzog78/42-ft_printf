# 42's ft_printf

<br>

## Info

__Author__ : `ysabik`

Version: `release1.0`

<br>

### Format

```
%[flags][width][.precision][length]specifier
```

---

<br><br>

## Mandatory

<br>

**Supported conversions :**

- `%c` : Character

- `%s` : String

- `%p` : Pointer

- `%d`/`%i` : Signed decimal integer

- `%u` : Unsigned decimal integer

- `%x` : Unsigned hexadecimal integer (lowercase)

- `%X` : Unsigned hexadecimal integer (uppercase)

- `%%` : Single '%' to the stream.

---

<br><br>

## Bonus

<br>

**Supported flags :**

- `-` :	Left-justify within the given field width.
		Right justification is the default.

- `+` :	Forces to precede the result with a plus or minus sign (+ or -).

- `(space)` :	If no sign is going to be written, a blank space is inserted before the value.

- `0` :	Pad with zeros instead of spaces.

- `#` :	Used with x or X specifiers the value is preceded with 0x or 0X respectively for values different than zero.
		By default, if no digits follow, no decimal point is written.

- `(width)`/`*` :	Minimum number of characters to be printed.
		If the value to be printed is shorter than this number,
		the result is padded with blank spaces.
		The value is not truncated even if the result is longer

- `.(precision)`/`.*` :	Precision specifies the minimum number of digits to be written.
		If the value to be written is shorter than this number,
		the result is padded with leading zeros.
		The value is not truncated even if the result is longer.

---

<br><br>

## Personal Additions

<br>

- [X] &nbsp; `*` flag : Dynamic width handling.

- [X] &nbsp; `.*` flag : Dynamic precision handling.

- [X] &nbsp; `(length)` argument : Length modifiers for integer conversions
	- [X] `hh` : Char
	- [X] `h` : Short
	- [X] ` ` : Int
	- [X] `l` : Long
	- [X] `ll` : Long Long

- [X] &nbsp; `o` conversion : Unsigned octal.

- [X] &nbsp; `-1` return value : Error handling. (incomprehensible and pointless)

- [X] &nbsp; negative `width`/`precision`.

- [ ] &nbsp; `f` conversion : Floating point number in normal (fixed-point) notation.

---

<br><br>

## Secret Message

#### Original

```
++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>.>---.++++++++++++.++.+++
+++.--.<<++.>>------.------------.+++++++++++++.<<.>>++++++.------------
.-------. +++++++++++++++++++.<<.>>----------------.+++++.+++++++++.---
----------.--.+ ++++++++++++++++.--------.+++++++++++++.<<.>>----------
-------------.+++.+++ ++++.---.----.+++++++++++++++++.---------------
--.-.<<.>>+++++.+++++.<<.>-------...
```

#### Decoded

**Encoding system used :** *`Brainfuck`*

```
Famous man that directly believed in ???
```

<br>

---
