fs = require 'fs'

if process.argv.length != 3
	console.log 'usage : coffee header2json.coffee <header file>'
	process.exit -1

text = '' + fs.readFileSync process.argv[2]
lines = text.split '\n'
# remove comments and preprocessor directives
lines = (l for l in lines when l.trim() isnt '' and l[0] isnt '#' and l[0] isnt '/' and l[0..1] isnt ' *')

lib = {}
for f in lines
	f = f.split ' '
	type = f.shift()
	f = f.join(' ').split('(')
	name = f.shift().trim()
	f = f.join('(').trim().replace(');', '').split(',')
	args = []
	args = (arg.trim().split(' ')[0] for arg in f) if f[0] isnt ''
	lib[name] = [type, args]

fileName = process.argv[2].split('/')[-1..-1][0].replace('.h', '.json')
fs.writeFileSync(fileName, JSON.stringify(lib, null, 2))
