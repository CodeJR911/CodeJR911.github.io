var mongoose = require('mongoose');
var Pet = require('./pets'); 

var pets = [
  {
    name: 'Buddy',
    species: 'Dog',
    breed: 'Golden Retriever',
    age: 2,
    imageUrl: 'https://example.com/dog1.jpg',
    description: 'A friendly and playful dog.',
  },
  {
    name: 'Lucy',
    species: 'Dog',
    breed: 'Labrador Retriever',
    age: 4,
    imageUrl: 'https://example.com/dog2.jpg',
    description: 'A loyal and affectionate dog.',
  },
  {
    name: 'Coco',
    species: 'Monkey',
    breed: 'Capuchin',
    age: 1,
    imageUrl: 'https://example.com/monkey1.jpg',
    description: 'A playful and intelligent monkey.',
  },
  {
    name: 'Charlie',
    species: 'Monkey',
    breed: 'Squirrel Monkey',
    age: 3,
    imageUrl: 'https://example.com/monkey2.jpg',
    description: 'A small and energetic monkey.',
  }
];

// Clear existing data and insert seed data
Pet.deleteMany({})
  .then(() => {
    return Pet.insertMany(pets);
  })
  .then(() => {
    console.log('Seed data inserted successfully!');
    mongoose.connection.close();
  })
  .catch((err) => {
    console.error('Error inserting seed data:', err);
    mongoose.connection.close();
  });
