var express = require('express');
var router = express.Router();
<<<<<<< HEAD
var controller = require('../Controllers/user'); // user controller

/* GET users listing. */
router.get('/', controller.userList); 

/* GET individual user page. */
router.get('/:userid', controller.userDetail); 

module.exports = router;

=======

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

module.exports = router;
>>>>>>> 2084a8e (app_server update)
