#!/bin/bash
zip -r9 _framework__win.zip _framework_.exe assets 
zip -j _framework__win.zip ../SDL2_dlls/*
