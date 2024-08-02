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

## Usage
``usage: ./ft_ls [-AGRSalrtvy1] [file ...]``

## Example of some flags
### -l : Same as original
![](https://github.com/prippa/my-projects-media/blob/main/ft_ls/OptimisticYellowishCatbird-size_restricted.png)
***
### -R : Same as original
![](https://github.com/prippa/my-projects-media/blob/main/ft_ls/recursive.png)
[more info](https://github.com/prippa/ft_ls/blob/master/ft_ls.en.pdf)
