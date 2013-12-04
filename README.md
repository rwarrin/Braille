#Braille

Converts a line of text into braille, or braille representation from a file into a text string.

## Sample Usage

```
Usage: ./braille [-t] translate <filename>
       ./braille [-c] convert <string>
```

String to braille:
`./braille -c "hello world"`
```
O. O. O. O. O. .. .O O. O. O. OO 
OO .O O. O. .O .. OO .O OO O. .O 
.. .. O. O. O. .. .O O. O. O. .. 
```

File to text (assuming sample.dat contains the above braille text):
`./braille -t sample.dat`
`hello world`

## Building the app

From the root project directory run `make` to build the app.

## Building libbraille

Run `make all` from inside the libbraille directory.
Change directory to the lib directory and run `ar rs libbraille.a brailletotext.o texttobraille.o`.

