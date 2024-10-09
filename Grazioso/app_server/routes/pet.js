var express = require('express');
var router = express.Router();
var controller = require('../Controllers/pet');

/* GET pet page. */
router.get('/:petid', controller.pet); // to display individual pets

module.exports = router;
