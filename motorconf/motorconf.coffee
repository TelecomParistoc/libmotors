program = require 'commander'
motors = require 'motors'

parameters =
	wheelsgap:  motors.wheelsGap
	tickspermeter: motors.ticksPerMeter
	linacc: motors.linear.acceleration
	angacc: motors.angular.acceleration
	linspeed: motors.linear.cruiseSpeed
	angspeed: motors.angular.cruiseSpeed
	linp: motors.linear.p
	lini: motors.linear.i
	lind: motors.linear.d
	angp: motors.angular.p
	angi: motors.angular.i
	angd: motors.angular.d

program
	.version('0.1.0')
	.arguments('<operation> <parameter> [value]')
	.action (operation, reg, val) ->
		if operation isnt 'write' and operation isnt 'read'
			console.log "First parameter must be 'read' or 'write', got #{operation}."
			process.exit 1
		if typeof parameters[reg] isnt 'function'
			console.log "Unknown parameter name #{reg}."
			process.exit 1
		if operation is 'write'
			if isNaN val
				console.log 'A valid value must be specified.'
				process.exit 1
			parameters[reg](parseFloat val)
			motors.writeFlash()
		else # operation must be 'read'
			console.log parameters[reg]()
	.on '--help', ->
		console.log '   <operation> : use "write" to write a new parameter value in flash,'
		console.log '                  and "read" to get the current parameter value'
		console.log '   <parameter> : a parameter name among : '
		console.log '                  wheelsgap, tickspermeter, linacc, angacc, linspeed, angspeed,'
		console.log '                  linp, lini, lind, angp, angi, angd'
		console.log '   [value]     : required for write, ignored for read : new parameter value'
		console.log ''
	.parse process.argv
