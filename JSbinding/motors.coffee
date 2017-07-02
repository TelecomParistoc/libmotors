ffi = require 'ffi'
motordriver = require('./headerloader.coffee')('libmotors', 'motordriver.json')
motion = require('./headerloader.coffee')('libmotors', 'motion.json')

moveCallback = null
turnCallback = null
moveToCallback = null
pathCallbacks = []
followCallback = null
unusedCallback = ffi.Callback('void', [], ->)

module.exports =
	######## motordriver.h functions ########
	wheelsGap: (val) ->
		motordriver.setWheelsGap(val) if typeof val is 'number'
		return motordriver.getWheelsGap()
	ticksPerMeter: (val) ->
		motordriver.setTicksPerMeter(val) if typeof val is 'number'
		return motordriver.getTicksPerMeter()

	angular:
		acceleration: (val) ->
			motordriver.setAngularMaxAcceleration(val) if typeof val is 'number'
			return motordriver.getAngularMaxAcceleration()
		cruiseSpeed: (val) ->
			motordriver.setAngularCruiseSpeed(val) if typeof val is 'number'
			return motordriver.getAngularCruiseSpeed()
		p: (val) ->
			motordriver.setAngularP(val) if typeof val is 'number'
			return motordriver.getAngularP()
		i: (val) ->
			motordriver.setAngularI(val) if typeof val is 'number'
			return motordriver.getAngularI()
		d: (val) ->
			motordriver.setAngularD(val) if typeof val is 'number'
			return motordriver.getAngularD()
	linear:
		acceleration: (val) ->
			motordriver.setLinearMaxAcceleration(val) if typeof val is 'number'
			return motordriver.getLinearMaxAcceleration()
		cruiseSpeed: (val) ->
			motordriver.setLinearCruiseSpeed(val) if typeof val is 'number'
			return motordriver.getLinearCruiseSpeed()
		p: (val) ->
			motordriver.setLinearP(val) if typeof val is 'number'
			return motordriver.getLinearP()
		i: (val) ->
			motordriver.setLinearI(val) if typeof val is 'number'
			return motordriver.getLinearI()
		d: (val) ->
			motordriver.setLinearD(val) if typeof val is 'number'
			return motordriver.getLinearD()
	writeFlash: motordriver.writeMotorsFlash

	x: (x) ->
		motordriver.setPosX(val) if typeof val is 'number'
		return motordriver.getPosX()
	y: (y) ->
		motordriver.setPosY(val) if typeof val is 'number'
		return motordriver.getPosY()
	heading: (val) ->
		motordriver.setHeading(val) if typeof val is 'number'
		return motordriver.getHeading()
	distance: (val) -> motordriver.getDistance()

	goalHeading: motordriver.setGoalHeading
	goalDistance: motordriver.setGoalDistance

	stop: motordriver.emergencyStop
	resume: motordriver.emergencyResume

	######## motion.h functions ########
	position: motion.setPositiong
	move: (dist, callback) ->
		moveCallback = unusedCallback
		moveCallback = ffi.Callback('void', [], callback) if callback?
		motion.move dist, moveCallback
	turn: (heading, callback) ->
		turnCallback = unusedCallback
		turnCallback = ffi.Callback('void', [], callback) if callback?
		motion.move heading, turnCallback
	moveTo: (x, y, angle, callback) ->
		moveToCallback = unusedCallback
		moveToCallback = ffi.Callback('void', [], callback) if callback?
		motion.moveTo x, y, angle, moveToCallback
	path:
		add: (x, y, angle, callback) ->
			if callback?
				pathCallbacks.push ffi.Callback('void', [], callback)
				motion.addPointInPath x, y, angle, pathCallbacks[pathCallbacks.length-1]
			else
				motion.addPointInPath x, y, angle, unusedCallback
		clear: motion.clearPath
		follow: (path, callback) ->
			followCallback = unusedCallback
			followCallback = ffi.Callback('void', [], callback) if callback?
			if path.length > 1
				motion.addPointInPath path[i].x, path[i].y, path[i].angle, unusedCallback for i in [0..path.length-2]
			if path.length > 0
				motion.addPointInPath path[path.length-1].x, path[path.length-1].y, path[path.length-1].angle, followCallback
