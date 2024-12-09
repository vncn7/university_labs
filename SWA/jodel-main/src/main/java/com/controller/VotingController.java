package com.controller;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.http.ResponseEntity;
import com.model.Voting;
import com.service.VotingService;
import java.util.List;

@RestController
@RequestMapping("/votes")
public class VotingController {
    
    @Autowired
    private VotingService votingService;
    
    // get all votings for a comment
    @GetMapping("/getVotings")
    public ResponseEntity<List<Voting>> getVotings(@RequestParam("commentId") Long commentId) {
        return ResponseEntity.ok(votingService.getVotings(commentId));
    }
    
    // get likes for a comment
    @GetMapping("/getLikes")
    public ResponseEntity<List<Voting>> getLikes(@RequestParam("commentId") Long commentId) {
        return ResponseEntity.ok(votingService.getLikes(commentId));
    }
    
    // get dislikes for a comment    
    @GetMapping("/getDislikes")
    public ResponseEntity<List<Voting>> getDislikes(@RequestParam("commentId") Long commentId) {
        return ResponseEntity.ok(votingService.getDislikes(commentId));
    }
    
    // Upvotes a comment
    @PostMapping("/upvote")
    public ResponseEntity<Voting> upvote(@RequestBody Voting voting) {
    	voting.setCreatedAt();
        voting.setValue(1); // Set the value to 1 (upvote)
        return ResponseEntity.ok(votingService.upvote(voting));
    }

    // Downvotes a comment
    @PostMapping("/downvote")
    public ResponseEntity<Voting> downvote(@RequestBody Voting voting) {
    	voting.setCreatedAt();
        voting.setValue(-1); // Set the value to -1 (downvote)
        return ResponseEntity.ok(votingService.downvote(voting));
    }
}
