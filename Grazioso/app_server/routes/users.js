var express = require('express');
var router = express.Router();
var controller = require('../Controllers/user'); // user controller

/* GET users listing. */
router.get('/', controller.userList); 

/* GET individual user page. */
router.get('/:userid', controller.userDetail); 

module.exports = router;

