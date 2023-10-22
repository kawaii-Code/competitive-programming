$prg = $args[0]
cl /Zi /EHsc "${prg}.cpp"
& "./${prg}.exe"
