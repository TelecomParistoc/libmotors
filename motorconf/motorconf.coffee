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
	ldir: motors.left.motorDirection
	lwheeldir: motors.left.wheelDirection
	rdir: motors.right.motorDirection
	rwheeldir: motors.right.wheelDirection
	distance: (dist) ->
		motors.goalDistance(dist) if typeof dist is 'number'
		return motors.distance()
	heading: (angle) ->
		motors.goalHeading(angle) if typeof angle is 'number'
		return motors.heading()

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
			# fix negative numbers mistaken for a flag
			val = process.argv.pop() if isNaN val
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
		console.log '      wheelsgap         : distance between the encoder wheels in mm'
		console.log '      tickspermeter     : number of ticks when the robot moves 1m forward'
		console.log '      linacc, angacc    : accelerations during speed up and slow down (mm/s^2 and deg/s^2)'
		console.log '      linspeed, angspeed: cruise speeds (mm/s and deg/s)'
		console.log '      linp, lini, lind  : linear PID coefficients'
		console.log '      angp, angi, angd  : angular PID coefficients'
		console.log '      ldir, lwheeldir   : left side hardware switches (0 or 1)'
		console.log '      rdir, rwheeldir   : right side hardware switches (0 or 1)'
		console.log '      distance          : distance to move (write) or traveled (read) in mm, signed'
		console.log '      heading           : heading to turn to (write) or current heading (read), absolute 0 to 360 CCW'
		console.log '   [value]     : required for write, ignored for read : new parameter value'
		console.log ''
	.parse process.argv
