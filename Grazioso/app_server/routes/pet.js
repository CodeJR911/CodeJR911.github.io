var express = require('express');
var router = express.Router();
var controller = require('../Controllers/pet');


/* GET home page. */
router.get('/', controller.pet);
 
module.exports = router;