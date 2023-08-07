// beats.c
//
// This program was written by Prithvi Sajit 
// on 22/04/2021
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.

#include "beats.h"

// Add your own #defines here.

#define MIN_OCTAVE 0
#define MAX_OCTAVE 9
#define MIN_KEY 0
#define MAX_KEY 11

//////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    // TODO: You will have to add extra fields here in Stage 2.
    struct beat *head;
};

// You don't have to use the provided struct beat, you are free to
// make your own struct instead.
// If you use the provided struct beat, you may add fields
// to it to store other information.

struct beat {
    // You may choose to add or change fields in this struct.
    struct note *notes;
    struct beat *next;
};

// You don't have to use the provided struct note, you are free to
// make your own struct instead.
// If you use the provided struct note, you add fields
// to it to store other information.

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

//////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.
struct note *get_last_note(struct note *head);


// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;

    // You do not need to change this function, unless you change
    // the implementation of struct beat.

    return new_beat;
}

// You need to implement the following functions.
// You can find descriptions of what each function should do in beats.h


//////////////////////////////////////////////////////////////////////
//                        My Functions                              //
//////////////////////////////////////////////////////////////////////
// Function to get the last note of the passed in argument
struct note *get_last_note(struct note *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    
    // Find last note
    struct note *current = head;
    while (current->next != NULL) {       
        current = current->next;
    }
    return current;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 1 Functions                         //
//////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {
    // This ensures that only valid inputs are accepted
    if (octave < MIN_OCTAVE || octave > MAX_OCTAVE) {
        return INVALID_OCTAVE; 
    }
    if (key < MIN_KEY || key > MAX_KEY) {
        return INVALID_KEY;
    }
    
    // Creating new note
    struct note *new = malloc(sizeof(struct note));
    new->octave = octave;
    new->key = key; 
    new->next = NULL;

    // Checking edge cases
    if (beat->notes == NULL) {
        beat->notes = new;
        return VALID_NOTE;
    }
    
    // Last note in a beat
    struct note *last = get_last_note(beat->notes);

    // Check if new note is higher than previous note
    int octave_higher = new->octave > last->octave;
    int octave_equal = new->octave == last->octave;
    int key_higher = new->key > last->key;
    if (octave_higher || (octave_equal && key_higher)) {
        last->next = new;
        return VALID_NOTE;
    }
    
    free(new);
    return NOT_HIGHEST_NOTE;
}

// Print the contents of a beat.
void print_beat(Beat beat) {
    if (beat == NULL) {
        return;
    }
    struct note *last = get_last_note(beat->notes);
    if (last == NULL) {
        printf("\n");
    }
    
    struct note *current = beat->notes;
    while (current != NULL) {
        if (current->key < 10) {
            printf("%d 0%d", current->octave, current->key);
            if (current->next == NULL /*&& i % 2 != 0*/) {
                printf("\n");
            }            
        }
        else if (current->key >= 10)  {
            printf("%d %d", current->octave, current->key);            
            if (current->next == NULL /*&& i % 2 != 0*/ ) {
                printf("\n");
            }
        }   
        if (current != NULL && current->next != NULL) {
            printf(" | ");      
        }
        current = current->next; 
    }    
    return;
}

// Count the number of notes in a beat that are in a given octave.
int count_notes_in_octave(Beat beat, int octave) {
    int output = 0;
    struct note *current = beat->notes;
    while (current != NULL) {
        if (current->octave == octave) {
            if (current->key != 0) {
                output++;  
            }
        }
        current = current->next;
    }
    return output;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 2 Functions                         //
//////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    struct track *current = malloc(sizeof(struct track));   
    // Note: there is no fprintf in this function, as the
    // Stage 1 autotests call create_track but expect it to return NULL
    // (so this function should do nothing in Stage 1).

    return current;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {
    
    
        
    return;
}

// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    printf("select_next_beat not implemented yet.\n");
    return TRACK_STOPPED;
}

// Print the contents of a track.
void print_track(Track track) {
    printf("print_track not implemented yet.\n");
    return;
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {
    printf("count_beats_left_in_track not implemented yet.\n");
    return 0;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 3 Functions                         //
//////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_beat but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    return;
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_track but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    return;
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {
    printf("remove_selected_beat not implemented yet.");
    return TRACK_STOPPED;
}
