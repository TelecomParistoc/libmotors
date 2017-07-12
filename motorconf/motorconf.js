// Generated by CoffeeScript 1.9.0
(function() {
  var motors, parameters, program;

  program = require('commander');

  motors = require('motors');

  parameters = {
    wheelsgap: motors.wheelsGap,
    tickspermeter: motors.ticksPerMeter,
    linacc: motors.linear.acceleration,
    angacc: motors.angular.acceleration,
    linspeed: motors.linear.cruiseSpeed,
    angspeed: motors.angular.cruiseSpeed,
    linp: motors.linear.p,
    lini: motors.linear.i,
    lind: motors.linear.d,
    angp: motors.angular.p,
    angi: motors.angular.i,
    angd: motors.angular.d
  };

  program.version('0.1.0')["arguments"]('<operation> <parameter> [value]').action(function(operation, reg, val) {
    if (operation !== 'write' && operation !== 'read') {
      console.log("First parameter must be 'read' or 'write', got " + operation + ".");
      process.exit(1);
    }
    if (typeof parameters[reg] !== 'function') {
      console.log("Unknown parameter name " + reg + ".");
      process.exit(1);
    }
    if (operation === 'write') {
      if (isNaN(val)) {
        console.log('A valid value must be specified.');
        process.exit(1);
      }
      parameters[reg](parseFloat(val));
      return motors.writeFlash();
    } else {
      return console.log(parameters[reg]());
    }
  }).on('--help', function() {
    console.log('   <operation> : use "write" to write a new parameter value in flash,');
    console.log('                  and "read" to get the current parameter value');
    console.log('   <parameter> : a parameter name among : ');
    console.log('                  wheelsgap, tickspermeter, linacc, angacc, linspeed, angspeed,');
    console.log('                  linp, lini, lind, angp, angi, angd');
    console.log('   [value]     : required for write, ignored for read : new parameter value');
    return console.log('');
  }).parse(process.argv);

}).call(this);
