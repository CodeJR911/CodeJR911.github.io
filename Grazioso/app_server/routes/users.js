var express = require('express');
var router = express.Router();
<<<<<<< HEAD
<<<<<<< HEAD
var controller = require('../Controllers/user'); // user controller

/* GET users listing. */
router.get('/', controller.userList); 

/* GET individual user page. */
router.get('/:userid', controller.userDetail); 

module.exports = router;

=======
=======
var controller = require('../Controllers/user'); // user controller
>>>>>>> 4586d48 (enhancements to app_api and app_server)

/* GET users listing. */
router.get('/', controller.userList); 

/* GET individual user page. */
router.get('/:userid', controller.userDetail); 

module.exports = router;
<<<<<<< HEAD
>>>>>>> 2084a8e (app_server update)
=======

>>>>>>> 4586d48 (enhancements to app_api and app_server)
