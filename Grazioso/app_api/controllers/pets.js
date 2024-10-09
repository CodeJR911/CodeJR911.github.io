var mongoose = require('mongoose');
var Pet = mongoose.model('Pet');

module.exports.petsGetAll = function(req, res) {
    console.log('GET /pets');
    Pet.find()
        .then(function(pets) {
            res.status(200).json(pets);
        })
        .catch(function(err) {
            res.status(500).json(err);
        });
};

module.exports.petsGetOne = function(req, res) {
    console.log('GET /pets/' + req.params.petId);
    Pet.findById(req.params.petId)
        .then(function(pet) {
            res.status(200).json(pet);
        })
        .catch(function(err) {
            res.status(500).json(err);
        });
};

module.exports.petsAddOne = function(req, res) {
    console.log('POST /pets');
    Pet.create({
        name: req.body.name,
        type: req.body.type,
        age: req.body.age,
        breed: req.body.breed,
        owner: req.body.owner,
        photo: req.body.photo
    })
        .then(function(pet) {
            res.status(201).json(pet);
        })
        .catch(function(err) {
            res.status(500).json(err);
        });
};

module.exports.petsFullUpdateOne = function(req, res) {
    console.log('PUT /pets/' + req.params.petId);
    Pet.findByIdAndUpdate(req.params.petId, {
        name: req.body.name,
        type: req.body.type,
        age: req.body.age,
        breed: req.body.breed,
        owner: req.body.owner,
        photo: req.body.photo
    }, {
        new: true
    })
        .then(function(pet) {
            res.status(204).json(pet);
        })
        .catch(function(