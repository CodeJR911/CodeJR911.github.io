import { TestBed } from '@angular/core/testing';
import { HttpClientTestingModule, HttpTestingController } from '@angular/common/http/testing';
import { PetDataService } from './pet-data.service';
import { Pet } from '../models/pet';

describe('PetDataService', () => {
  let service: PetDataService;
  let httpTestingController: HttpTestingController;

  beforeEach(() => {
    TestBed.configureTestingModule({
      imports: [HttpClientTestingModule], // Import HttpClientTestingModule
      providers: [PetDataService]
    });

    service = TestBed.inject(PetDataService);
    httpTestingController = TestBed.inject(HttpTestingController);
  });

  afterEach(() => {
    httpTestingController.verify(); // Verify that no outstanding requests are left
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });

  it('should fetch pets from the API', () => {
    const mockPets: Pet[] = [
      {
        id: 1,
        name: 'Buddy',
        species: 'Dog',
        breed: 'Golden Retriever',
        age: 2,
        imageUrl: 'https://example.com/dog.jpg',
        description: 'A friendly and playful dog.',
        adoptionStatus: 'Available'
      },
      // Add more mock pets as needed
    ];

    service.getPets().subscribe(pets => {
      expect(pets).toEqual(mockPets);
    });

    const req = httpTestingController.expectOne('api/pets');
    expect(req.request.method).toBe('GET');
    req.flush(mockPets);
  });

  it('should add a new pet to the API', () => {
    const newPet: Pet = {
      id: 1,
      name: 'Lucy',
      species: 'Cat',
      breed: 'Siamese',
      age: 1,
      imageUrl: 'https://example.com/cat.jpg',
      description: 'A curious and playful cat.',
      adoptionStatus: 'Available'
    };

    service.addPet(newPet).subscribe();

    const req = httpTestingController.expectOne('api/pets');
    expect(req.request.method).toBe('POST');
    expect(req.request.body).toEqual(newPet);
    req.flush(newPet);
  });
});
