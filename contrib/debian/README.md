
Debian
====================
This directory contains files used to package hootd/hoot-qt
for Debian-based Linux systems. If you compile hootd/hoot-qt yourself, there are some useful files here.

## hoot: URI support ##


hoot-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install hoot-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your hoot-qt binary to `/usr/bin`
and the `../../share/pixmaps/hoot128.png` to `/usr/share/pixmaps`

hoot-qt.protocol (KDE)

