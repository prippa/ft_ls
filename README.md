# ft_ls
## Project from UNIX branch in school 42
### My own implementation of most useful command ls in UNIX systems
#### Of course, I did not realize all the existing flags of ls, only the most important ones and some my own

## Implemented flags
### Originals
* -l : Long format, displaying Unix file types, permissions, number of hard links, owner, group, size, last-modified date and filename.
* -R : Recursively lists subdirectories. The command ``ls -R /`` would therefore list all files.
* -a : Lists all files in the given directory, including those whose names start with "." (which are hidden files in Unix). By default, these files are excluded from the list.
* -r : Reverses the order of the sort, giving reverse alphabetic or the
oldest first, as appropriate.
* -t : Sort the list of files by modification time.
* -1 : Forces output into one-entry-per-line format. This is the default
when the output is not directed to a terminal.
* -A : Lists all entries except . (dot) and .. (dot-dot).
* -S : Sort the list of files by size in kilobytes.
***
### My own
* -G : Iridescent illumination of files.
* -v : prints count of all objects in directory
* -y : Sort by object name size from lowest to biggest

## Example of some flags
### -l : Here some example original vs mine
![](https://thumbs.gfycat.com/OptimisticYellowishCatbird-size_restricted.gif)
***
### -R : Here some example original vs mine
![](https://thumbs.gfycat.com/ReflectingMeekGadwall-size_restricted.gif)
***
### -G : My special bonus, just for fun :)
![](https://thumbs.gfycat.com/BiodegradableIllustriousComet-size_restricted.gif)
[more info](https://github.com/prippa/ft_ls/blob/master/ft_ls.en.pdf)
