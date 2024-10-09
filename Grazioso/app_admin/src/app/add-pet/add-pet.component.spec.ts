import { ComponentFixture, TestBed } from '@angular/core/testing';
import { ReactiveFormsModule } from '@angular/forms';
import { AddPetComponent } from './add-pet.component';
import { PetDataService } from '../services/pet-data.service';
import { HttpClientTestingModule } from '@angular/common/http/testing';

describe('AddPetComponent', () => {
  let component: AddPetComponent;
  let fixture: ComponentFixture<AddPetComponent>;
  let petDataService: PetDataService;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [
        AddPetComponent,
        ReactiveFormsModule, // Import ReactiveFormsModule for form testing
        HttpClientTestingModule // Import HttpClientTestingModule for mocking HTTP requests
      ],
      providers: [PetDataService] // Provide PetDataService for testing
    })
    .compileComponents();

    fixture = TestBed.createComponent(AddPetComponent);
    component = fixture.componentInstance;
    petDataService = TestBed.inject(PetDataService);
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  // Add more tests here to validate form functionality, data submission, etc.
  // For example:
  it('should create a pet form with valid controls', () => {
    expect(component.petForm).toBeDefined();
    expect(component.petForm.get('name')).toBeDefined();
    expect(component.petForm.get('species')).toBeDefined();
    // ... add more assertions for other form controls
  });

  it('should submit the form and call the petDataService', () => {
    // Mock the petDataService.addPet method
    spyOn(petDataService, 'addPet').and.returnValue(Promise.resolve());

    // Fill the form with test data
    component.petForm.setValue({
      name: 'Test Pet',
      species: 'Dog',
      breed: 'Golden Retriever',
      age: 2,
      imageUrl: 'https://example.com/pet-image.jpg',
      description: 'A friendly dog',
      adoptionStatus: 'Available'
    });

    // Submit the form
    component.onSubmit();

    // Verify that the petDataService.addPet method was called
    expect(petDataService.addPet).toHaveBeenCalled();
  });

  // ... add more tests as needed
});
