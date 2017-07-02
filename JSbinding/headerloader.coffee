fs = require 'fs'
ffi = require 'ffi'
simpleCallback = ffi.Function('void', [])

module.exports = (libname, file) ->
	lib = JSON.parse(fs.readFileSync(file))
	for f of lib
		lib[f][1][i] = simpleCallback for i in [0..lib[f][1].length-1] when lib[f][1][i] is 'void'
	return ffi.Library libname, lib
