# PegDF, another lightweight pdf library

## Description

PegDF uses "peg" grammar for pdf file structure parsing. The parser walks through
a file one object/xref/etc. a time, until reached EOF. This grammar is oblivious of
pdf's cross reference structure, instead just store each object in memory, in a b-plus tree.

External logics captures the "Catalog", and from there recovers the whole content tree.

By doing this way, a single pass walking replaces the necessities of re-contruct document
based on cross reference table.

## Build Instructions


## APIs

## Utililties

## Examples

## ToDos


